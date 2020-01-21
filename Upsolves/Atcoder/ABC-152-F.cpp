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
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v, i - 1);
        G[v].emplace_back(u, i - 1);
    }
    int m;
    cin >> m;
    vector<pair<int, int>> cond(m);
    vector<long long> path(m);
    function<pair<bool, long long>(int, int, int, long long)> dfs = [&](int u, int par, int dest, long long path_mask) {
        if (u == dest) {
            return make_pair(true, path_mask);
        }
        for (auto &p : G[u]) {
            int v = p.first;
            int e = p.second;
            if (v == par) {
                continue;
            }
            auto nxt = dfs(v, u, dest, path_mask | (1LL << e));
            if (nxt.first) {
                return make_pair(true, nxt.second);
            }
        }
        return make_pair(false, 0LL);
    };
    for (int i = 0; i < m; ++i) {
        cin >> cond[i].first >> cond[i].second;
        path[i] = dfs(cond[i].first, -1, cond[i].second, 0).second;
    }
    long long ans = (1LL << (n - 1));
    for (int mask = 1; mask < (1 << m); ++mask) {
        long long path_mask = 0;
        int set = 0;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                path_mask |= path[i];
                ++set;
            }
        }
        int edges = __builtin_popcountll(path_mask);
        ans += (set % 2 == 1 ? -1 : 1) * (1LL << (n - 1 - edges));
    }
    cout << ans << "\n";
    return 0;
}

