#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> se(n);
        for (int i = 0; i < n; ++i) {
            cin >> se[i].first.first >> se[i].first.second;
            se[i].second = i;
        }
        sort(se.begin(), se.end());
        vector<int> col(n, -1);
        for (int i = 0, r = -1; i < n; ++i) {
            if (se[i].first.first >= r) {
                col[se[i].second] = 0;
                r = se[i].first.second;
            }
        }
        bool ok = true;
        for (int i = 0, r = -1; i < n; ++i) {
            if (col[se[i].second] == -1) {
                if (se[i].first.first < r) {
                    ok = false;
                } else {
                    col[se[i].second] = 1;
                    r = se[i].first.second;
                }
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 0; i < n; ++i) {
                cout << (col[i] ? "J" : "C");
            }
            cout << "\n";
        }
    }
    return 0;
}

