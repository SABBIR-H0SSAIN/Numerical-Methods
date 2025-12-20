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
        
        double v = (p - x[n-1]) / h;
        
        vector<vector<double>> diff(n, vector<double>(n));
        
        for(int i = 0; i < n; i++) {
            diff[i][0] = y[i];
        }
        
        for(int j = 1; j < n; j++) {
            for(int i = n - 1; i >= j; i--) {
                diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
            }
        }
        
        double result = y[n-1];
        double v_term = 1.0;
        
        for(int i = 1; i < n; i++) {
            v_term *= (v + (i - 1));
            result += (v_term * diff[n-1][i]) / fact(i);
        }
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "For x=" << p <<endl;
        cout << "Result: " << setprecision(6) << result << endl;
        cout << endl;
    }
    
    return 0;
}
