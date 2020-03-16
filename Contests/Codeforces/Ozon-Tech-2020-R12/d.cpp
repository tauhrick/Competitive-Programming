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
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int queries = 0;
    auto get_lca = [&](int u, int v) {
        ++queries;
        assert(queries <= n / 2);
        cout << "? " << u << " " << v << endl;
        int lca_node;
        cin >> lca_node;
        return lca_node;
    };
    vector<int> par(n + 1, -1);
    vector<bool> seen(n + 1);
    function<int(int, int)> dfs = [&](int u, int p) {
        seen[u] = true;
        int nodes = 1;
        vector<int> consider;
        for (auto &v : G[u]) {
            if (!seen[v]) {
                int sub = dfs(v, u);
                nodes += sub;
                if (sub & 1) {
                    consider.emplace_back(v);
                }
            }
        }
        if (p != 0) {
            consider.emplace_back(p);
        }
        debug(u, consider);
        for (int i = 0; i + 1 < consider.size(); i += 2) {
            int lca = get_lca(consider[i], consider[i + 1]);
            if (lca == u) {
                par[consider[i]] = par[consider[i + 1]] = i;
            } else if (lca == consider[i]) {
                par[consider[i + 1]] = u;
                par[u] = consider[i];
            } else {
                par[consider[i]] = u;
                par[u] = consider[i + 1];
            }
        }
        if (p == 0) {
            if (consider.size() & 1) {
                int lca = get_lca(u, consider.back());
                if (lca == u) {
                    par[consider.back()] = u;
                } else {
                    par[u] = consider.back();
                }
            }
        }
        debug(u, par);
        return nodes;
    };
    dfs(1, 0);
    int roots = 0;
    for (int i = 1; i <= n; ++i) {
        if (par[i] == -1) {
            cout << "! " << i << endl;
            ++roots;
        }
    }
    assert(roots == 1);
}

