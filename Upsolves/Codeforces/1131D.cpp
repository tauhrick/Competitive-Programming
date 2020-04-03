#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    const int N = 4e4 + 10;
    vector<vector<int>> facts(N);
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            facts[j].emplace_back(i);
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<pair<int, int>> B(N, make_pair(INT_MAX, INT_MAX));
        for (int i = 1; i < N; ++i) {
            int up = upper_bound(facts[i].begin(), facts[i].end(), a) - facts[i].begin();
            if (up != facts[i].size()) {
                B[i] = min(B[i], make_pair(facts[i][up] - a, facts[i][up]));
            }
            if (up - 1 >= 0) {
                B[i] = min(B[i], make_pair(a - facts[i][up - 1], facts[i][up - 1]));
            }
        }
        int res = INT_MAX;
        vector<int> v;
        for (int cc = 1; cc < N; ++cc) {
            for (auto &bb : facts[cc]) {
                int curr = abs(cc - c) + abs(bb - b) + B[bb].first;
                if (curr < res) {
                    res = curr;
                    v = {B[bb].second, bb, cc};
                }
            }
        }
        cout << res << "\n";
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

