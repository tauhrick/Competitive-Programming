#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int l = 0;
        while (l < s.size() && s[l] == '0') {
            ++l;
        }
        int r = s.size() - 1;
        while (r >= 0 && s[r] == '0') {
            --r;
        }
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            cnt += s[i] == '0';
        }
        cout << cnt << "\n";
    }
    return 0;
}

