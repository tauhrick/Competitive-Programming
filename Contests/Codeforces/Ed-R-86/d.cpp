#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }
    sort(C.rbegin(), C.rend());
    vector<int> sz(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> sz[i];
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = (int) res.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if ((int) res[mid].size() <= sz[C[i]] - 1) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (!res.empty() && (int) res[lo].size() <= sz[C[i]] - 1) {
            res[lo].emplace_back(C[i]);
        } else {
            res.emplace_back(vector<int>{C[i]});
        }
    }
    cout << res.size() << "\n";
    for (auto &v : res) {
        cout << v.size() << " ";
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

