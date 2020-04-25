#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> P(n + 1);
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> P[i];
            pos[P[i]] = i;
        }
        set<int> rem;
        for (int i = 1; i <= n; ++i) {
            rem.insert(i);
        }
        vector<int> cnt(n + 1, 1);
        multiset<int> cnts(cnt.begin() + 1, cnt.end());
        bool ok = true;
        for (int x = 1; x <= n; ++x) {
            if (!rem.count(pos[x]) || cnt[pos[x]] != *cnts.rbegin()) {
                ok = false;
                break;
            }
            rem.erase(pos[x]);
            cnts.erase(cnts.find(cnt[pos[x]]));
            auto it = rem.upper_bound(pos[x]);
            if (it != rem.end()) {
                int nxt = *it;
                cnts.erase(cnts.find(cnt[nxt]));
                cnt[nxt] += cnt[x];
                cnts.insert(cnt[nxt]);
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}

