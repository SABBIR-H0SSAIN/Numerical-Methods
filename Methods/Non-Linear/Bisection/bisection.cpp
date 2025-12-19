#include<bits/stdc++.h>
using namespace std;

ofstream fout;

double f(double x, vector<double>& coef)
{
    double result = 0;
    int n = coef.size();
    for(int i = 0; i < n; i++)
    {
        result += coef[i] * pow(x, n - 1 - i);
    }
    return result;
}

void bisection(double a, double b, double tol, vector<double>& coef)
{
    int iteration = 0;
    double mid;
    
    if(f(a, coef) * f(b, coef) > 0)
    {
        return;
    }
    
    while(true)
    {
        iteration++;
        mid = (a + b) / 2.0;
        double fmid = f(mid, coef);
        
        if(fabs(fmid) < tol)
        {
            break;
        }
        if(f(a, coef) * fmid < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }
    fout << "Root = " << mid << " found in " << iteration << " iterations" << endl;
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
        
        vector<double> coef(degree + 1);
        for(int i = 0; i <= degree; i++)
        {
            fin >> coef[i];
        }
        
        double a, b, tol, steps;
        fin >> a >> b >> tol >> steps;
        
        fout << "Test Case " << tc << ":" << endl;
        fout << "Polynomial: ";
        for(int i = 0; i <= degree; i++)
        {
            if(i > 0 && coef[i] >= 0) fout << "+";
            fout << coef[i];
            if(degree - i > 0) fout << "x^" << degree - i << " ";
        }
        fout << endl;
        fout << "Interval: [" << a << ", " << b << "]" << endl;
        fout << "Tolerance: " << tol << endl;
        fout << "Step size: " << steps << endl;
        
        double x1 = a;
        double x2 = a + steps;
        bool found = false;
        
        while(x2 <= b)
        {
            double f1 = f(x1, coef);
            double f2 = f(x2, coef);
            if(f1 * f2 < 0)
            {
                found = true;
                bisection(x1, x2, tol, coef);
            }
            x1 = x2;
            x2 = x2 + steps;
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
