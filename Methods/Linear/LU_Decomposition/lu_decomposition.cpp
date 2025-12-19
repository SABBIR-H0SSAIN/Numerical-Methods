#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

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

        vector<vector<double>> L(n, vector<double>(n, 0));
        vector<vector<double>> U(n, vector<double>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                U[i][j] = a[i][j];
                for (int k = 0; k < i; k++)
                {
                    U[i][j] -= L[i][k] * U[k][j];
                }
            }

            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    L[i][i] = 1;
                }
                else
                {
                    L[j][i] = a[j][i];
                    for (int k = 0; k < i; k++)
                    {
                        L[j][i] -= L[j][k] * U[k][i];
                    }
                    L[j][i] /= U[i][i];
                }
            }
        }

        vector<double> y(n);
        for (int i = 0; i < n; i++)
        {
            y[i] = b[i];
            for (int j = 0; j < i; j++)
            {
                y[i] -= L[i][j] * y[j];
            }
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = y[i];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= U[i][j] * x[j];
            }
            x[i] /= U[i][i];
        }

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
    fout << "LU Decomposition Method" << endl;
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
