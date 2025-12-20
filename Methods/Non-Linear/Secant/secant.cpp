#include<bits/stdc++.h>
using namespace std;

ofstream fout;

double f(double x, vector<double>& coefficient)
{
    int degree = coefficient.size() - 1;
    double res = 0;
    for(int i = degree; i >= 0; i--)
    {
        res += coefficient[i] * pow(x, i);
    }
    return res;
}

void secant(double x0, double x1, double tol, vector<double>& coefficient)
{
    int iteration = 0;
    double x_new;

    while(true)
    {
        iteration++;
        double fx1 = f(x1, coefficient);
        double fx0 = f(x0, coefficient);

        if(fabs(fx1 - fx0) < 1e-12)
        {
            return;
        }

        x_new = x1 - ((x1 - x0) / (fx1 - fx0)) * fx1;

        if(fabs(x_new) > 1e-12 && fabs((x_new - x1) / x_new) < tol)
        {
            break;
        }

        if(iteration > 100)
        {
            break;
        }

        x0 = x1;
        x1 = x_new;
    }

    fout << "Root found: " << x_new << endl;
}

int main()
{
    ifstream fin("input.txt");
    fout.open("output.txt");

    int t;
    fin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        int degree;
        fin >> degree;

        vector<double> coefficient(degree + 1);
        for(int i = degree; i >= 0; i--)
        {
            fin >> coefficient[i];
        }

        double tol;
        fin >> tol;

        fout << "Test case=" << tc << endl;
        fout << "Polynomial: ";
        for(int i = degree; i >= 0; i--)
        {
            if(i < degree && coefficient[i] >= 0) fout << "+";
            fout << coefficient[i];
            if(i > 0) fout << "x^" << i << " ";
        }
        fout << endl;
        fout << "Tolerance: " << tol << endl;
        fout << endl;

        bool found = false;
        for(double x = -10.0; x <= 10.0; x += 0.1)
        {
            if(fabs(f(x, coefficient)) < tol)
            {
                fout << "Root found: " << x << endl;
                found = true;
            }
            else if(f(x, coefficient) * f(x + 0.1, coefficient) < 0)
            {
                found = true;
                secant(x, x + 0.1, tol, coefficient);
            }
        }

        if(!found)
        {
            fout << "No Solution found in the given interval" << endl;
        }
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
