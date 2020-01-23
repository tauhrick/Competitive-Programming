#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> X(n);
    vector<int> Y(n);
    vector<int> Z(n);
    double cx = 0, cy = 0, cz = 0;
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
        cx += X[i];
        cy += Y[i];
        cz += Z[i];
    }
    cx /= n;
    cy /= n;
    cz /= n;
    const int EN = 1e6;
    double delta = 0.1;
    for (int iter = 0; iter < EN; ++iter) {
        double max_dist = 0;
        int max_ind = -1;
        for (int i = 0; i < n; ++i) {
            double dx = X[i] - cx;
            double dy = Y[i] - cy;
            double dz = Z[i] - cz;
            double curr_dist = dx * dx + dy * dy + dz * dz;
            if (curr_dist > max_dist) {
                max_dist = curr_dist;
                max_ind = i;
            }
        }
        cx += (X[max_ind] - cx) * delta;
        cy += (Y[max_ind] - cy) * delta;
        cz += (Z[max_ind] - cz) * delta;
        delta *= 0.999;
    }
    cout << cx << ' ' << cy << ' ' << cz << '\n';
    return 0;
}

