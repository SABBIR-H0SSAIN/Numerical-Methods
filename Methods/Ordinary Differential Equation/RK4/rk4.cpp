#include<bits/stdc++.h>
using namespace std;

ofstream fout("output.txt");

double f(double x, double y)
{
    return x + y;
}

int main()
{
    ifstream fin("input.txt");
    
    int t;
    fin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        double x0, y0, h, Xn;
        fin >> x0 >> y0 >> h >> Xn;
        
        fout << "Test case=" << tc << endl;
        fout << fixed << setprecision(6);
        
        double x = x0;
        double y = y0;
        
        while(x + 1e-12 < Xn)
        {
            double k1 = h * f(x, y);
            double k2 = h * f(x + h/2, y + k1/2);
            double k3 = h * f(x + h/2, y + k2/2);
            double k4 = h * f(x + h, y + k3);
            
            y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
            x = x + h;
        }
        
        fout << "At x=" << x << ", y=" << y << endl;
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
