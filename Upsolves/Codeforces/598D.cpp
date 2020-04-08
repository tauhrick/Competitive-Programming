#include <bits/stdc++.h>
using namespace std;

const vector<int> dr = {0, 0, 1, -1};
const vector<int> dc = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> G(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> G[i][j];
        }
    }
    vector<vector<bool>> seen(n + 1, vector<bool>(m + 1));
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    vector<pair<int, int>> cc;
    int walls = 0;
    function<void(int, int)> dfs = [&](int r, int c) {
        if (G[r][c] == '*') {
            ++walls;
            return;
        }
        seen[r][c] = true;
        cc.emplace_back(r, c);
        for (int dir = 0; dir < 4; ++dir) {
            int _r = r + dr[dir];
            int _c = c + dc[dir];
            if (1 <= _r && _r <= n && 1 <= _c && _c <= m && !seen[_r][_c]) {
                dfs(_r, _c);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!seen[i][j] && G[i][j] == '.') {
                walls = 0;
                cc.clear();
                dfs(i, j);
                for (auto [r, c] : cc) {
                    ans[r][c] = walls;
                }
            }
        }
    }
    while (k--) {
        int r, c;
        cin >> r >> c;
        cout << ans[r][c] << "\n";
    }
    return 0;
}

