#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<int, string>> moves;
    auto out = [&](int cnt, string s) {
        moves.emplace_back(cnt, s);
    };
    int r = 1;
    while (r != n + 1) {
        if (m > 1) {
            if (r & 1) {
                out(m - 1, "R");
            } else {
                out(m - 1, "L");
            }
        }
        if (r + 1 <= n) {
            out(1, "D");
        }
        ++r;
    }
    r = n;
    while (r != 0) {
        if (m > 1) {
            if (r - 1 > 0) {
                out(1, "UD");
                if (m - 2 > 0) {
                    if (r & 1) {
                        out(m - 2, "LUD");
                    } else {
                        out(m - 2, "RUD");
                    }
                }
                if (r & 1) {
                    out(1, "LU");
                } else {
                    out(1, "RU");
                }
            } else {
                out(m - 1, "L");
            }
        } else {
            out(1, "U");
        }
        --r;
    }
    r = 1;
    assert(moves.size() <= 3000);
    vector<pair<int, string>> v;
    for (auto &move : moves) {
        if (move.first * move.second.size() >= k) {
            int n_cnt = k / move.second.size();
            if (n_cnt) {
                v.emplace_back(n_cnt, move.second);
            }
            int rem = k % move.second.size();
            if (rem) {
                v.emplace_back(1, move.second.substr(0, rem));
            }
            break;
        } else {
            k -= move.first * move.second.size();
            v.emplace_back(move.first, move.second);
        }
    }
    cout << v.size() << "\n";
    int x = 0;
    for (auto &move : v) {
        cout << move.first << " " << move.second << "\n";
        x += move.first * move.second.size();
    }
    return 0;
}

