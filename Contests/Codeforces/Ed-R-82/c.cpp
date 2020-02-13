#include <bits/stdc++.h>
using namespace std;

void test_case() {
    string s;
    cin >> s;
    vector<vector<int>> G(26);
    vector<int> deg(26);
    set<pair<int, int>> edges;
    for (int i = 0; i < s.size() - 1; ++i) {
        int a = s[i] - 'a';
        int b = s[i + 1] - 'a';
        int u = min(a, b);
        int v = max(a, b);
        if (edges.count({u, v})) {
            continue;
        }
        edges.insert({u, v});
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        ++deg[u];
        ++deg[v];
    }
    int root = -1;
    int ones = 0;
    for (int i = 0; i < 26; ++i) {
        if (deg[i] == 1) {
            ++ones;
            root = i;
        } else if (deg[i] > 2) {
            cout << "NO\n";
            return;
        }
    }
    if (s.size() != 1 && ones != 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    auto get_ch = [&](int x) {
        cout << char('a' + x);
    };
    vector<int> done(26);
    function<void(int)> dfs = [&](int u) {
        get_ch(u);
        done[u] = true;
        for (auto &v : G[u]) {
            if (!done[v]) {
                dfs(v);
            }
        }
    };
    if (root != -1) {
        dfs(root);
    }
    for (int i = 0; i < 26; ++i) {
        if (!done[i]) {
            get_ch(i);
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        test_case();
    }
    return 0;
}
