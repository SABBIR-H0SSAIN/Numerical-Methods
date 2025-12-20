#include <bits/stdc++.h>
using namespace std;

long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int case_count = 1;
    while(cin >> n) {
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double h = x[1] - x[0];
        
        double p;
        cin >> p;
        
        double u = (p - x[0]) / h;
        
        vector<vector<double>> diff(n, vector<double>(n));
        
        for(int i = 0; i < n; i++) {
            diff[i][0] = y[i];
        }
        
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - j; i++) {
                diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
            }
        }
        
        double result = y[0];
        double u_term = 1.0;
        
        for(int i = 1; i < n; i++) {
            u_term *= (u - (i - 1));
            result += (u_term * diff[0][i]) / fact(i);
        }
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "For x=" << p <<endl;
        cout << "Result: " << setprecision(6) << result << endl;
        cout << endl;
    }
    
    return 0;
}
