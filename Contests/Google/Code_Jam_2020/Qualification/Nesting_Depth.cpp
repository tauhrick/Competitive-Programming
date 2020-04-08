#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        string s;
        cin >> s;
        string res;
        int depth = 0;
        for (auto &ch : s) {
            int req = ch - '0';
            while (depth < req) {
                res += "(";
                ++depth;
            }
            while (depth > req) {
                res += ")";
                --depth;
            }
            res += ch;
        }
        while (depth > 0) {
            res += ")";
            --depth;
        }
        cout << res << "\n";
    }
    return 0;
}

