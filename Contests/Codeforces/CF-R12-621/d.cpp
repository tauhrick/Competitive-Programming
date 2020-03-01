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
    int n, m, k;	
    cin >> n >> m >> k;
    vector<int> A(k);
    for (int i = 0; i < k; ++i) {
        cin >> A[i];
    }
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    auto bfs = [&](int src) {
        queue<int> q;
        vector<int> dist(n + 1);
        vector<bool> seen(n + 1);
        q.push(src);
        seen[src] = true;
        int d = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                int u = q.front();
                q.pop();
                dist[u] = d;
                for (auto &v : G[u]) {
                    if (seen[v]) {
                        continue;
                    }
                    seen[v] = true;
                    q.push(v);
                }
            }
            ++d;
        }
        return dist;
    };
    vector<int> dist_1 = bfs(1);
    vector<int> dist_n = bfs(n);
    debug(dist_1);
    debug(dist_n);
    int ans = 0;
    multiset<int> mst;
    sort(A.begin(), A.end(), [&](auto a, auto b) {
        return dist_1[a] < dist_1[b];
    });
    for (int i = 0; i < k; ++i) {
        mst.insert(dist_n[A[i]]);
    }
    for (int i = 0; i < k - 1; ++i) {
        mst.erase(mst.find(dist_n[A[i]]));
        ans = max(ans, dist_1[A[i]] + 1 + *mst.rbegin());
    }
    ans = min(ans, dist_1[n]);
    cout << ans << "\n";
    return 0;
}

