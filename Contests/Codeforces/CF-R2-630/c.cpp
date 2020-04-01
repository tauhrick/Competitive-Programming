#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int res = 0;
        vector<bool> done(k);
        for (int i = 0; i < k; ++i) {
            if (done[i]) {
                continue;
            }
            map<int, int> cnt;
            for (int j = i; j < s.size(); j += k) {
                ++cnt[s[j]];
            }
            if ((n - i - 1) % k != i) {
                done[i] = done[(n - i - 1) % k] = true;
                for (int j = n - i - 1; j >= 0; j -= k) {
                    ++cnt[s[j]];
                }
            }
            int mx = 0;
            int j = -1;
            for (auto &p : cnt) {
                if (p.second > mx) {
                    mx = p.second;
                    j = p.first;
                }
            }
            for (auto &p : cnt) {
                if (p.first != j) {
                    res += p.second;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}

