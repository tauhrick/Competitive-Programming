#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        int x;
        cin >> x;
        vector<vector<int>> grid(n, vector<int>(n));
        int trace = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> grid[j][k];
                if (j == k) {
                    trace += grid[j][k];
                }
            }
        }
        int rows = 0, cols = 0;
        for (int j = 0; j < n; ++j) {
            set<int> row_set, col_set;
            for (int k = 0; k < n; ++k) {
                row_set.emplace(grid[j][k]);
                col_set.emplace(grid[k][j]);
            }
            rows += row_set.size() != n;
            cols += col_set.size() != n;
        }
        cout << trace << " " << rows << " " << cols << "\n";
    }
    return 0;
}

