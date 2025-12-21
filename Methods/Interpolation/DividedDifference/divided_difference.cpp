#include<bits/stdc++.h>
using namespace std;

ofstream fout("output.txt");

int main()
{
    ifstream fin("input.txt");
    
    int t;
    fin >> t;
    
    fout << fixed << setprecision(6);
    
    for(int tc = 1; tc <= t; tc++)
    {
        int n;
        fin >> n;
        
        fout << "Test case " << tc << ":" << endl;
        
        if(n < 2)
        {
            fout << "Error: At least 2 data points are required for interpolation." << endl;
            fout << endl;
            continue;
        }
        
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++)
            fin >> x[i];
        
        for(int i = 0; i < n; i++)
            fin >> y[i];
        
        bool hasDuplicate = false;
        for(int i = 0; i < n && !hasDuplicate; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(abs(x[i] - x[j]) < 1e-9)
                {
                    hasDuplicate = true;
                    break;
                }
            }
        }
        
        if(hasDuplicate)
        {
            fout << "Error: Duplicate x values found. All x values must be distinct." << endl;
            fout << endl;
            double xp;
            fin >> xp;
            continue;
        }
        
        double xp;
        fin >> xp;
        
        vector<vector<double>> table(n, vector<double>(n, 0));
        
        for(int i = 0; i < n; i++)
            table[i][0] = y[i];
        
        for(int j = 1; j < n; j++)
        {
            for(int i = 0; i < n - j; i++)
            {
                table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
            }
        }
        
        double result = table[0][0];
        double term = 1.0;
        
        for(int i = 1; i < n; i++)
        {
            term *= (xp - x[i - 1]);
            result += table[0][i] * term;
        }
        
        fout << "P(" << xp << ") = " << result << endl;
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
