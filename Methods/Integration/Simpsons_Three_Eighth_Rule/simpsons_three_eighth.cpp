#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    double l, u;
    cin >> l >> u;
    
    double h = x[1] - x[0];
    
    double sum3 = 0.0;
    for(int i = 1; i < n-1; i++) {
        if(i % 3 != 0) {
            sum3 += y[i];
        }
    }
    
    double sum2 = 0.0;
    for(int i = 3; i < n-1; i += 3) {
        sum2 += y[i];
    }
    
    double integral = (3.0 * h / 8.0) * (y[0] + 3.0 * sum3 + 2.0 * sum2 + y[n-1]);
    
    cout << "Integration from range (" << l << " to " << u << ")" << endl;
    cout << fixed << setprecision(6);
    cout << "Result : " << integral << endl;
    
    return 0;
}
