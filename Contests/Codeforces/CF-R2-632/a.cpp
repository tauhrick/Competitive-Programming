#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> G(n, vector<char>(m, 'B'));
        G[0][0] = 'W';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << G[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}

