#include<bits/stdc++.h>
using namespace std;

ofstream fout;

double f(double a, vector<double>& coefficient)
{
    int degree = coefficient.size() - 1;
    double res = 0;
    for(int i = degree; i >= 0; i--)
    {
        res += coefficient[i] * pow(a, i);
    }
    return res;
}

double df(double a, vector<double>& coefficient)
{
    int degree = coefficient.size() - 1;
    double res = 0;
    for(int i = degree; i > 0; i--)
    {
        res += i * coefficient[i] * pow(a, i - 1);
    }
    return res;
}

void newton_raphson(double a, double e, vector<double>& coefficient)
{
    int iteration = 0;
    double x = a;

    while(true)
    {
        double fx = f(x, coefficient);
        double dfx = df(x, coefficient);

        if(fabs(dfx) < 1e-12)
        {
            return;
        }

        double xnew = x - (fx / dfx);
        iteration++;

        if(fabs(xnew - x) < e)
        {
            fout << "Root found: " << xnew << endl;
            break;
        }

        if(iteration > 100)
        {
            break;
        }

        x = xnew;
    }
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

        double steps, E;
        fin >> steps >> E;

        double amax = 0;
        for(int i = 0; i < degree; i++)
        {
            amax = max(amax, fabs(coefficient[i] / coefficient[degree]));
        }

        double xmax = 1 + amax;
        double x1 = -xmax, x2 = xmax;

        fout << "Test case=" << tc << endl;
        fout << "Polynomial: ";
        for(int i = degree; i >= 0; i--)
        {
            if(i < degree && coefficient[i] >= 0) fout << "+";
            fout << coefficient[i];
            if(i > 0) fout << "x^" << i << " ";
        }
        fout << endl;
        fout << "Search Interval: [" << x1 << ", " << x2 << "]" << endl;
        fout << "Tolerance: " << E << endl;
        fout << endl;

        double a = x1, b = x1 + steps;
        bool found = false;

        while(b <= x2)
        {
            double x0 = (a + b) / 2.0;

            if(fabs(f(a, coefficient)) < E)
            {
                fout << "Root found: " << a << endl;
                found = true;
            }
            else if((f(a, coefficient) * f(b, coefficient)) < 0)
            {
                found = true;
                newton_raphson(x0, E, coefficient);
            }
            a = b;
            b += steps;
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
