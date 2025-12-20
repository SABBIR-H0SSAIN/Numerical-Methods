#include<bits/stdc++.h>
using namespace std;

ofstream fout("output.txt");
vector<double> coef;
int degree;

double f(double x)
{
    double result = 0;
    for(int i = 0; i <= degree; i++)
    {
        result += coef[i] * pow(x, i);
    }
    return result;
}

void false_position(double a, double b, double e)
{
    int iteration = 0;
    double mid;
    if(f(a) * f(b) > 0)
    {
        return;
    }
    while(true)
    {
        iteration++;
        mid = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
        double fmid = f(mid);
        if(fabs(fmid) < e)
        {
            break;
        }
        if(f(a) * f(mid) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }
    fout << "Root=" << mid << " in iterations=" << iteration << endl;
}

int main()
{
    ifstream fin("input.txt");
    
    int t;
    fin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        fin >> degree;
        coef.clear();
        coef.resize(degree + 1);
        
        for(int i = degree; i >= 0; i--)
        {
            fin >> coef[i];
        }
        
        double a, b, steps, E;
        fin >> a >> b >> steps >> E;
        
        fout << "Test case=" << tc << endl;
        fout << fixed << setprecision(6);
        
        double x1 = a;
        double x2 = a + steps;
        bool found = false;
        
        while(x2 <= b)
        {
            if(fabs(f(x1)) < E)
            {
                fout << "Root=" << x1 << " in iterations=0" << endl;
                found = true;
            }
            else if(f(x1) * f(x2) < 0)
            {
                false_position(x1, x2, E);
                found = true;
            }
            x1 = x2;
            x2 = x2 + steps;
        }
        if(fabs(f(x1)) < E)
        {
            fout << "Root=" << x1 << " in iterations=0" << endl;
            found = true;
        }
        
        if(!found)
        {
            fout << "No root found in given interval" << endl;
        }
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
