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
        
        double dy = 0;
        double d2y = 0;
        
        if (n >= 2) {
            dy += diff[n-1][1]; 
        }
        
        if (n >= 3) {
            double t2 = 2*v + 1;
            double t2_ = 2;
            
            dy += (diff[n-1][2] / fact(2)) * t2;
            d2y += (diff[n-1][2] / fact(2)) * t2_;
        }
        
        if (n >= 4) {
            double t3 = 3*v*v + 6*v + 2;
            double t3_ = 6*v + 6;
            
            dy += (diff[n-1][3] / fact(3)) * t3;
            d2y += (diff[n-1][3] / fact(3)) * t3_;
        }
        
        if (n >= 5) {
            double t4 = 4*pow(v, 3) + 18*v*v + 22*v + 6;
            double t4_ = 12*v*v + 36*v + 22;
            
            dy += (diff[n-1][4] / fact(4)) * t4;
            d2y += (diff[n-1][4] / fact(4)) * t4_;
        }
        
        if (n >= 6) {
            double t5 = 5*pow(v, 4) + 40*pow(v, 3) + 105*v*v + 100*v + 24;
            double t5_ = 20*pow(v, 3) + 120*v*v + 210*v + 100;
            
            dy += (diff[n-1][5] / fact(5)) * t5;
            d2y += (diff[n-1][5] / fact(5)) * t5_;
        }

        dy /= h;
        d2y /= (h * h);
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout<<"For point x="<<p<<endl;
        cout << setprecision(6);
        cout << "1st Derivative f'(x) = " << dy << endl;
        cout << "2nd Derivative f''(x) = " << d2y << endl;
        cout << endl;
    }
    
    return 0;
}
