#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if ((n / 2) & 1) {
            cout << "NO";
        } else {
            cout << "YES\n";
            int m = n / 2;
            vector<int> st;
            int st_tot = 0;
            for (int i = 1; i <= m; ++i) {
                st.emplace_back(2 * i);
                st_tot += 2 * i;
            }
            vector<int> en;
            int en_tot = 0;
            for (int i = 1; i < m; ++i) {
                en.emplace_back(2 * i - 1);
                en_tot += 2 * i - 1;
            }
            en.emplace_back(st_tot - en_tot);
            for (auto &i : st) {
                cout << i << " ";
            }
            for (auto &i : en) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

