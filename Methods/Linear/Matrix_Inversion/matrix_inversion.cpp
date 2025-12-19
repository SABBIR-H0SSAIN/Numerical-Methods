#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

double determinant(vector<vector<double>> &A, int n)
{
    if (n == 1)
    {
        return A[0][0];
    }
    double detA = 0;
    vector<vector<double>> minor_mat(n - 1, vector<double>(n - 1));
    int sign = 1;
    for (int col = 0; col < n; col++)
    {
        int minor_row = 0;
        for (int row = 1; row < n; row++)
        {
            int minor_col = 0;
            for (int j = 0; j < n; j++)
            {
                if (col == j)
                    continue;
                minor_mat[minor_row][minor_col] = A[row][j];
                minor_col++;
            }
            minor_row++;
        }
        detA += sign * A[0][col] * determinant(minor_mat, n - 1);
        sign = -sign;
    }
    return detA;
}

vector<vector<double>> cofactor(vector<vector<double>> &A, int n)
{
    vector<vector<double>> co_mat(n, vector<double>(n));
    vector<vector<double>> minor_mat(n - 1, vector<double>(n - 1));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int minor_row = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == row)
                    continue;
                int minor_col = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == col)
                        continue;
                    minor_mat[minor_row][minor_col] = A[i][j];
                    minor_col++;
                }
                minor_row++;
            }
            int sign = ((row + col) % 2 == 0) ? 1 : -1;
            co_mat[row][col] = sign * determinant(minor_mat, n - 1);
        }
    }
    return co_mat;
}

vector<vector<double>> transpose(vector<vector<double>> &A, int n)
{
    vector<vector<double>> transposed(n, vector<double>(n));
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            transposed[col][row] = A[row][col];
    return transposed;
}

int calculateRank(vector<vector<double>> mat, int rows, int cols)
{
    int rank = 0;
    for (int col = 0, row = 0; col < cols && row < rows; col++)
    {
        int maxRow = row;
        for (int k = row + 1; k < rows; k++)
        {
            if (abs(mat[k][col]) > abs(mat[maxRow][col]))
            {
                maxRow = k;
            }
        }

        if (abs(mat[maxRow][col]) < EPS)
        {
            continue;
        }

        swap(mat[row], mat[maxRow]);

        for (int k = row + 1; k < rows; k++)
        {
            double factor = mat[k][col] / mat[row][col];
            for (int j = col; j < cols; j++)
            {
                mat[k][j] -= factor * mat[row][j];
            }
        }
        rank++;
        row++;
    }
    return rank;
}

int checkSolutionType(vector<vector<double>> &A, vector<double> &b, int n, int &rankA, int &rankAug)
{
    vector<vector<double>> augMatrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augMatrix[i][j] = A[i][j];
        }
        augMatrix[i][n] = b[i];
    }

    rankA = calculateRank(A, n, n);
    rankAug = calculateRank(augMatrix, n, n + 1);

    if (rankA < rankAug)
    {
        return -1;
    }
    else if (rankA < n)
    {
        return 1;
    }
    return 0;
}

void solveSystem(vector<vector<double>> a, vector<double> b, int n, int problemNo, ofstream &fout)
{
    fout << "Problem " << problemNo << endl;
    fout << string(40, '-') << endl;

    int rankA, rankAug;
    int solutionType = checkSolutionType(a, b, n, rankA, rankAug);

    double detA = determinant(a, n);
    fout << "Determinant of A = " << detA << endl;

    if (abs(detA) < EPS)
    {
        fout << "Matrix is NOT INVERTIBLE" << endl;
    }
    else
    {
        fout << "Matrix is INVERTIBLE" << endl;
    }

    if (solutionType == -1)
    {
        fout << "Solution Type: NO SOLUTION" << endl;
    }
    else if (solutionType == 1)
    {
        fout << "Solution Type: INFINITE SOLUTIONS" << endl;
    }
    else
    {
        fout << "Solution Type: UNIQUE SOLUTION" << endl;

        vector<vector<double>> co_mat = cofactor(a, n);
        vector<vector<double>> adj = transpose(co_mat, n);

        vector<vector<double>> inverse(n, vector<double>(n));
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
                inverse[row][col] = adj[row][col] / detA;

        vector<double> x(n, 0);
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
                x[row] += inverse[row][col] * b[col];

        fout << "Solution:" << endl;
        for (int i = 0; i < n; i++)
        {
            fout << "x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fout << endl
         << endl;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << fixed << setprecision(6);
    fout << "Matrix Inversion Method" << endl;
    fout << "=======================" << endl
         << endl;

    int t;
    fin >> t;

    for (int p = 1; p <= t; p++)
    {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<double> b(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            fin >> b[i];
        }

        solveSystem(a, b, n, p, fout);
    }

    fin.close();
    fout.close();

    return 0;
}
