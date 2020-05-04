#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    auto lr = vector(n + 2, vector(n + 2, false));
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        bool ok = true;
        for (int j = i; j <= n; ++j) {
            if (s[j] == ')') {
                --cnt;
            } else {
                ++cnt;
            }
            ok = ok && cnt >= 0;
            lr[i][j] = ok;
        }
    }
    auto rl = vector(n + 2, vector(n + 2, false));
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        bool ok = true;
        for (int j = i; j >= 1; --j) {
            if (s[j] == '(') {
                --cnt;
            } else {
                ++cnt;
            }
            ok = ok && cnt >= 0;
            rl[j][i] = ok;
        }
    }
    int prs = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if ((j - i + 1) % 2 == 0 && lr[i][j] && rl[i][j]) {
                ++prs;
            }
        }
    }
    cout << prs << "\n";
    return 0;
}

