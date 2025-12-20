#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n;
    inFile >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> x[i] >> y[i];
    }

    double x_pred;
    inFile >> x_pred;

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double a = (sum_y - b * sum_x) / n;

    double y_pred = a + b * x_pred;

    outFile << fixed << setprecision(6);
    outFile << "Linear Regression: y = a + bx" << endl;
    outFile << "n = " << n << endl;
    outFile << "a = " << a << endl;
    outFile << "b = " << b << endl;
    outFile << "For x = " << x_pred << ", y = " << y_pred << endl;

    inFile.close();
    outFile.close();

    return 0;
}
