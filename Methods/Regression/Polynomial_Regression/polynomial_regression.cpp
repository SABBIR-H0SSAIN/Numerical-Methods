#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n, degree;
    inFile >> n >> degree;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> x[i] >> y[i];
    }

    double x_pred;
    inFile >> x_pred;

    int m = degree + 1;
    vector<double> sumX(2 * degree + 1, 0);
    vector<double> sumXY(m, 0);

    for (int i = 0; i < n; i++)
    {
        double xi = 1;
        for (int j = 0; j <= 2 * degree; j++)
        {
            sumX[j] += xi;
            xi *= x[i];
        }
        xi = 1;
        for (int j = 0; j < m; j++)
        {
            sumXY[j] += xi * y[i];
            xi *= x[i];
        }
    }

    vector<vector<double>> A(m, vector<double>(m + 1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = sumX[i + j];
        }
        A[i][m] = sumXY[i];
    }

    for (int i = 0; i < m; i++)
    {
        int maxRow = i;
        for (int k = i + 1; k < m; k++)
        {
            if (fabs(A[k][i]) > fabs(A[maxRow][i]))
                maxRow = k;
        }
        swap(A[i], A[maxRow]);

        for (int k = i + 1; k < m; k++)
        {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= m; j++)
            {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    vector<double> coef(m);
    for (int i = m - 1; i >= 0; i--)
    {
        coef[i] = A[i][m];
        for (int j = i + 1; j < m; j++)
        {
            coef[i] -= A[i][j] * coef[j];
        }
        coef[i] /= A[i][i];
    }

    double y_pred = 0, xi = 1;
    for (int i = 0; i < m; i++)
    {
        y_pred += coef[i] * xi;
        xi *= x_pred;
    }

    outFile << fixed << setprecision(6);
    outFile << "Polynomial Regression (degree " << degree << ")" << endl;
    outFile << "n = " << n << endl;
    for (int i = 0; i < m; i++)
    {
        outFile << "a" << i << " = " << coef[i] << endl;
    }
    outFile << "For x = " << x_pred << ", y = " << y_pred << endl;

    inFile.close();
    outFile.close();

    return 0;
}
