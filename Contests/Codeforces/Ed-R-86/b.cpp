#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int n = s.size();
        if (s == string(n, '0') || s == string(n, '1')) {
            cout << s;
        } else {
            string res;
            for (int i = 0; i < n; ++i) {
                res += "01";
            }
            cout << res;
        }
        cout << "\n";
    }
    return 0;
}

