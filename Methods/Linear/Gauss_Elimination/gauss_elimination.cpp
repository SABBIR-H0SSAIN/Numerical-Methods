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

int checkSolutionType(vector<vector<double>> &augMatrix, int n, int &rankA, int &rankAug)
{
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = augMatrix[i][j];
        }
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

void solveSystem(vector<vector<double>> a, int n, int problemNo, ofstream &fout)
{
    fout << "Problem " << problemNo << endl;
    fout << string(40, '-') << endl;

    int rankA, rankAug;
    int solutionType = checkSolutionType(a, n, rankA, rankAug);

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

        for (int col = 0, row = 0; col < n && row < n; col++)
        {
            int maxRow = row;
            for (int k = row + 1; k < n; k++)
            {
                if (abs(a[k][col]) > abs(a[maxRow][col]))
                {
                    maxRow = k;
                }
            }

            if (abs(a[maxRow][col]) < EPS)
            {
                continue;
            }

            swap(a[row], a[maxRow]);

            for (int k = row + 1; k < n; k++)
            {
                double factor = a[k][col] / a[row][col];
                for (int j = col; j <= n; j++)
                {
                    a[k][j] -= factor * a[row][j];
                }
            }
            row++;
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
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
    fout << "Gauss Elimination Method" << endl;
    fout << "========================" << endl
         << endl;

    int t;
    fin >> t;

    for (int p = 1; p <= t; p++)
    {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        solveSystem(a, n, p, fout);
    }

    fin.close();
    fout.close();

    return 0;
}
