#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        string t;
        cin >> s >> t;
        vector<vector<int>> pos(256);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i]].emplace_back(i);
        }
        int ind = -1;
        int cnt = 1;
        bool bad = false;
        for (int i = 0; i < t.size(); ++i) {
            if (pos[t[i]].empty()) {
                bad = true;
                break;
            }
            int ii = lower_bound(pos[t[i]].begin(), pos[t[i]].end(), ind + 1) - pos[t[i]].begin();
            if (ii == pos[t[i]].size()) {
                ++cnt;
                ind = pos[t[i]][0];
            } else {
                ind = pos[t[i]][ii];
            }
        }
        cout << (bad ? -1 : cnt) << "\n";
    }
    return 0;
}

