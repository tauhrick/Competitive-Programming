#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    double res = 1e20;
    for (int i1 = 0; i1 < n; ++i1) {
        int i2 = (i1 + 1) % n;
        int i3 = (i2 + 1) % n;
        double A = (y[i3] - y[i1]);
        double B = -(x[i3] - x[i1]);
        double C = -1LL * (y[i3] - y[i1]) * x[i3] + 1LL * (x[i3] - x[i1]) * y[i3];
        double num = abs(A * x[i2] + B * y[i2] + C);
        double den = 2 * sqrt(1LL * A * A + 1LL * B * B);
        double dist = num / den;
        res = min(res, dist);
    }
    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}

