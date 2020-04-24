#include <bits/stdc++.h>

using namespace std;

void test_case() {
    long long xx, yy;
    cin >> xx >> yy;
    long long x = abs(xx);
    long long y = abs(yy);
    string res;
    for (int bit = 0; bit <= 40; ++bit) {
        long long curr = 1LL << bit;
        if (curr > x && curr > y) {
            break;
        }
        int bx = (x >> bit) & 1;
        int by = (y >> bit) & 1;
        if (bx && by) {
            for (int nxt = bit + 1; nxt <= 40; ++nxt) {
                int nx = (x >> nxt) & 1;
                int ny = (y >> nxt) & 1;
                if (nx && !ny) {
                    y += 1LL << nxt;
                    if (yy > 0) {
                        res += "S";
                    } else {
                        res += "N";
                    }
                } else if (!nx && ny) {
                    x += 1LL << nxt;
                    if (xx > 0) {
                        res += "W";
                    } else {
                        res += "E";
                    }
                } else if (!nx && !ny) {
                    x += 1LL << nxt;
                    if (xx > 0) {
                        res += "W";
                    } else {
                        res += "E";
                    }
                }
            }
        } else if (bx && !by) {
            if (xx > 0) {
                res += "E";
            } else {
                res += "W";
            }
        } else if (!bx && by) {
            if (yy > 0) {
                res += "N";
            } else {
                res += "S";
            }
        } else {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;

}

