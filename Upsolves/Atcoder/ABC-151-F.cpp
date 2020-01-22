#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    double cx = 0;
    double cy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        cx += x[i];
        cy += y[i];
    }
    cx /= n;
    double gradient = 0.1;
    double max_dist;
    for (int ctr = 0; ctr < 1000000; ++ctr) {
        int max_ind = -1;
        max_dist = 0;
        for (int i = 0; i < n; ++i) {
            double dx = cx - x[i];
            double dy = cy - y[i];
            double curr_dist = dx * dx + dy * dy;
            if (curr_dist > max_dist) {
                max_dist = curr_dist;
                max_ind = i;
            }
        }
        cx += (x[max_ind] - cx) * gradient;
        cy += (y[max_ind] - cy) * gradient;
        gradient *= 0.999;
    }
    cout << sqrt(max_dist) << "\n";
    return 0;
}

