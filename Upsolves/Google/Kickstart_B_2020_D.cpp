#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 10;

vector<double> lg_fact;

void pre() {
    lg_fact.resize(MX);
    lg_fact[0] = 0;
    for (int i = 1; i < MX; ++i) {
        lg_fact[i] = lg_fact[i - 1] + log2(i);
    }
}

void test_case() {
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    if (w == 1 || h == 1) {
        cout << 0. << "\n";
        return;
    }
    auto get_prob = [&](int rr, int cc) {
        if (rr <= 0 || cc <= 0) {
            return (double) 0;
        }
        int dr = rr - 1;
        int dc = cc - 1;
        int N = dr + dc;
        int C = dc;
        double pwr = lg_fact[N] - lg_fact[C] - lg_fact[N - C] - N;
        return pow(2, pwr);
    };
    double prob = 1;
    for (int col = l; col <= r; ++col) {
        if (col == w) {
            for (int row = 1; row <= u - 1; ++row) {
                prob -= get_prob(row, col - 1) * 0.5;
            }
        } else {
            prob -= get_prob(u - 1, col) * 0.5;
        }
    }
    for (int row = u; row <= d; ++row) {
        if (row == h) {
            for (int col = 1; col <= l - 1; ++col) {
                prob -= get_prob(row - 1, col) * 0.5;
            }
        } else {
            prob -= get_prob(row, l - 1) * 0.5;
        }
    }
    cout << prob << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    pre();
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;
}

