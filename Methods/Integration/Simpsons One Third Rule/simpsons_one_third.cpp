#include <bits/stdc++.h>
using namespace std;

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
        
        double l, u;
        cin >> l >> u;
        
        double h = x[1] - x[0];
        
        double sum4 = 0.0;
        for(int i = 1; i < n-1; i += 2) {
            sum4 += y[i];
        }
        
        double sum2 = 0.0;
        for(int i = 2; i < n-1; i += 2) {
            sum2 += y[i];
        }
        
        double integral = (h / 3.0) * (y[0] + 4.0 * sum4 + 2.0 * sum2 + y[n-1]);
    
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "Integration from range (" << l << " to " << u << ")" << endl;
        cout << setprecision(6);
        cout << "Result : " << integral << endl;
        cout << endl;
    }
    
    return 0;
}
