#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;	
    cin >> n >> m >> k;
    vector<pair<int, int>> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i].first >> s[i].second;
    }
    vector<pair<int, int>> f(k);
    for (int i = 0; i < k; ++i) {
        cin >> f[i].first >> f[i].second;
    }
    string res;
    auto out = [&](auto st) {
        res += st;
    };
    for (int i = 0; i < n - 1; ++i) {
        out("U");
    }
    for (int i = 0; i < m - 1; ++i) {
        out("L");
    }
    int r = 1, c = 1;
    while (true) {
        if (r & 1) {
            if (c == m) {
                if (r == n) {
                    break;
                }
                out("D");
                ++r;
            } else {
                out("R");
                ++c;
            }
        } else {
            if (c == 1) {
                if (r == n) {
                    break;
                }
                out("D");
                ++r;
            } else {
                out("L");
                --c;
            }
        }
    }
    assert(res.size() <= 2 * n * m);
    cout << res.size() << "\n" << res << "\n";
    return 0;
}

