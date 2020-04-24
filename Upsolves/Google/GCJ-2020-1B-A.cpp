#include <bits/stdc++.h>

using namespace std;

const string V = "NS";
const string H = "EW";

void test_case() {
    int x, y;
    cin >> x >> y;
    int v_ind = y < 0;
    int h_ind = x < 0;
    x = abs(x);
    y = abs(y);
    if ((x + y) % 2 == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    string res;
    while (max(x, y) > 0) {
        bool take_x = (x % 2) == 1;
        bool take_y = (y % 2) == 1;
        x /= 2;
        y /= 2;
        if (take_x && !take_y) {
            if ((x & 1) == (y & 1) && !(x == 0 && y == 0)) {
                res += H[!h_ind];
                ++x;
            } else {
                res += H[h_ind];
            }
        } else if (!take_x && take_y) {
            if ((x & 1) == (y & 1) && !(x == 0 && y == 0)) {
                res += V[!v_ind];
                ++y;
            } else {
                res += V[v_ind];
            }
        } else {
            assert(false);
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

