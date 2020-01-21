#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<vector<int>> open(n + 2);
    vector<vector<int>> close(n + 2);
    vector<bool> vis(n + 1);
    int mn, mx;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        mn = min(mn, u);
        mx = max(mx, u);
        for (auto &v : G[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };
    int cc = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++cc;
            mn = INT_MAX;
            mx = INT_MIN;
            dfs(i);
            open[mn].emplace_back(cc);
            close[mx + 1].emplace_back(cc);
        }
    }
    int res = 0;
    set<int> to_match;
    vector<int> seen;
    for (int i = 1; i <= n + 1; ++i) {
        for (auto &c : close[i]) {
            to_match.erase(c);
        }
        if (to_match.empty()) {
            res += max(0, (int) seen.size() - 1);
            seen.clear();
        }
        for (auto &o : open[i]) {
            to_match.insert(o);
            seen.emplace_back(o);
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
