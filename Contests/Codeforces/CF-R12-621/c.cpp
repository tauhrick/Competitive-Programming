#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto &ch : s) {
        ++cnt[ch - 'a'];
    }
    long long ans = 0;
    for (auto &c : cnt) {
        ans = max(ans, 1LL * c);
    }
    map<string, long long> prs;
    for (int i = 0; i < s.size(); ++i) {
        --cnt[s[i] - 'a'];
        for (int nxt = 0; nxt < 26; ++nxt) {
            string key;
            key += s[i];
            key += 'a' + nxt;
            prs[key] += cnt[nxt];
        }
    }
    for (auto &p : prs) {
        ans = max(ans, p.second);
    }
    cout << ans << "\n";
    return 0;
}

