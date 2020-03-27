#include <bits/stdc++.h>
using namespace std;

string to_string(char ch) {
    return "'" + string(1, ch) + "'";
}

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

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <size_t N>
string to_string(bitset<N> v) {
    return v.to_string();
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < v.size(); ++i) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> dep(n + 1);
    vector<int> par(n + 1);
    function<void(int, int, int)> pre = [&](int u, int p, int d) {
        dep[u] = d;
        par[u] = p;
        for (auto &v : G[u]) {
            if (v != p) {
                pre(v, u, d + 1);
            }
        }
    };
    pre(1, 1, 0);
    vector<vector<int>> Q(m);
    vector<vector<int>> pos(n + 1);
    for (int j = 0; j < m; ++j) {
        int k;
        cin >> k;
        int st = 1;
        int mx_dep = 0;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            if (dep[x] > mx_dep) {
                mx_dep = dep[x];
                st = x;
            }
            Q[j].emplace_back(x);
        }
        pos[st].emplace_back(j);
    }
    vector<bool> ans(m);
    function<void(int, int, set<int>&)> dfs = [&](int u, int p, set<int> &s) {
        for (auto &v : G[u]) {
            if (v != p) {
                s.insert(v);
            }
        }
        for (auto &i : pos[u]) {
            bool ok = true;
            for (auto &v : Q[i]) {
                if (!s.count(v)) {
                    ok = false;
                    break;
                }
            }
            ans[i] = ok;
        }
        for (auto &v : G[u]) {
            if (v != p) {
                dfs(v, u, s);
            }
        }
        for (auto &v : G[u]) {
            if (v != p) {
                s.erase(v);
            }
        }
    };
    set<int> st = {1};
    dfs(1, 1, st);
    for (int i = 0; i < m; ++i) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
    return 0;
}

