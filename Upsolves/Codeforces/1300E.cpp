#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;	
    cin >> n;
    vector<int> A(n + 1);
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        pre[i] = pre[i - 1] + A[i];
    }
    vector<pair<int, long long>> hull = {{0, 0}};
    for (int i = 1; i <= n; ++i) {
        hull.emplace_back(i, pre[i]);
        auto bad = [&](int i1, int i2, int i3) {
            long long ii = (hull[i3].first - hull[i1].first) * (hull[i2].second - hull[i1].second);
            long long jj = (hull[i2].first - hull[i1].first) * (hull[i3].second - hull[i1].second);
            return ii - jj >= 0;
        };
        while (hull.size() >= 3 && bad(hull.size() - 3, hull.size() - 2, hull.size() - 1)) {
            hull.erase(hull.end() - 2);
        }
    }
    vector<double> P(1);
    for (int i = 1; i < hull.size(); ++i) {
        int cnt = hull[i].first - hull[i - 1].first;
        for (int j = 1; j <= cnt; ++j) {
            P.emplace_back(hull[i - 1].second + (1. * (hull[i].second - hull[i - 1].second) * j) / cnt);
        }
    }
    cout << fixed << setprecision(10);
    for (int i = 1; i < P.size(); ++i) {
        cout << P[i] - P[i - 1] << "\n";
    }
    return 0;
}

