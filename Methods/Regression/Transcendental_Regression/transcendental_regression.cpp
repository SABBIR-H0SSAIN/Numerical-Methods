#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n, type;
    inFile >> n >> type;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> x[i] >> y[i];
    }

    double x_pred;
    inFile >> x_pred;

    vector<double> X(n), Y(n);

    if (type == 1)
    {
        for (int i = 0; i < n; i++)
        {
            X[i] = x[i];
            Y[i] = log(y[i]);
        }
    }
    else if (type == 2)
    {
        for (int i = 0; i < n; i++)
        {
            X[i] = log(x[i]);
            Y[i] = log(y[i]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            X[i] = log(x[i]);
            Y[i] = y[i];
        }
    }

    double sum_X = 0, sum_Y = 0, sum_XY = 0, sum_X2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum_X += X[i];
        sum_Y += Y[i];
        sum_XY += X[i] * Y[i];
        sum_X2 += X[i] * X[i];
    }

    double B = (n * sum_XY - sum_X * sum_Y) / (n * sum_X2 - sum_X * sum_X);
    double A = (sum_Y - B * sum_X) / n;

    double a, b, y_predicted;

    outFile << fixed << setprecision(6);

    if (type == 1)
    {
        a = exp(A);
        b = B;
        y_predicted = a * exp(b * x_pred);
        outFile << "Exponential Regression: y = a * e^(bx)" << endl;
    }
    else if (type == 2)
    {
        a = exp(A);
        b = B;
        y_predicted = a * pow(x_pred, b);
        outFile << "Power Regression: y = a * x^b" << endl;
    }
    else
    {
        a = A;
        b = B;
        y_predicted = a + b * log(x_pred);
        outFile << "Logarithmic Regression: y = a + b*ln(x)" << endl;
    }

    outFile << "n = " << n << endl;
    outFile << "a = " << a << endl;
    outFile << "b = " << b << endl;
    outFile << "For x = " << x_pred << ", y = " << y_predicted << endl;

    inFile.close();
    outFile.close();

    return 0;
}
