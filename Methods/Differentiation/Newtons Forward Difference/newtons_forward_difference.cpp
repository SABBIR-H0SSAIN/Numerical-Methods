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
        
        double dy = 0;
        double d2y = 0;
        
        if(n >= 2) {
            dy += diff[0][1];
        }
        
        if(n >= 3) {
            double t2 = 2*u - 1;
            double t2_ = 2;
            
            dy += (diff[0][2] / fact(2)) * t2;
            d2y += (diff[0][2] / fact(2)) * t2_;
        }
        
        if(n >= 4) {
            double t3 = 3*u*u - 6*u + 2;
            double t3_ = 6*u - 6;
            
            dy += (diff[0][3] / fact(3)) * t3;
            d2y += (diff[0][3] / fact(3)) * t3_;
        }
        
        if(n >= 5) {
            double t4 = 4*pow(u, 3) - 18*u*u + 22*u - 6;
            double t4_ = 12*u*u - 36*u + 22;
            
            dy += (diff[0][4] / fact(4)) * t4;
            d2y += (diff[0][4] / fact(4)) * t4_;
        }
        
        if(n >= 6) {
            double t5 = 5*pow(u, 4) - 40*pow(u, 3) + 105*u*u - 100*u + 24;
            double t5_ = 20*pow(u, 3) - 120*u*u + 210*u - 100;
            
            dy += (diff[0][5] / fact(5)) * t5;
            d2y += (diff[0][5] / fact(5)) * t5_;
        }
        
        dy /= h;
        d2y /= (h * h);
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "For point x=" << p << endl;
        cout << setprecision(6);
        cout << "1st Derivative f'(x) = " << dy << endl;
        cout << "2nd Derivative f''(x) = " << d2y << endl;
        cout << endl;
    }
    
    return 0;
}
