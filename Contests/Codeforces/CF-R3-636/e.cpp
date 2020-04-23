#include <bits/stdc++.h>

using namespace std;

string to_string(char ch) {
    return "'" + string(1, ch) + "'";
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <size_t N>
string to_string(bitset<N> v) {
    return v.to_string();
}

template <typename A>
string to_string(A v) {
    string res = "{", sep;
    for (const auto x : v) {
        res += sep + to_string(x);
        sep = ", ";
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
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        vector<int> P(m + 1);
        for (int i = 1; i <= m; ++i) {
            cin >> P[i];
        }
        sort(P.begin() + 1, P.end());
        vector<long long> pref1(m + 1);
        vector<long long> pref2(m + 1);
        for (int i = 1; i <= m; ++i) {
            pref1[i] = pref1[i - 1] + P[i];
            pref2[i] = pref2[i - 1] + 2 * P[i];
        }
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        auto get_dist = [&](int src) {
            vector<int> dist(n + 1);
            vector<bool> seen(n + 1);
            queue<int> q;
            q.push(src);
            seen[src] = true;
            int d = 0;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    auto u = q.front();
                    q.pop();
                    dist[u] = d;
                    for (auto &v : G[u]) {
                        if (!seen[v]) {
                            seen[v] = true;
                            q.push(v);
                        }
                    }
                }
                ++d;
            }
            return dist;
        };
        auto dist_a = get_dist(a);
        auto dist_b = get_dist(b);
        auto dist_c = get_dist(c);
        debug(dist_a);
        debug(dist_b);
        debug(dist_c);
        long long best = LLONG_MAX;
        for (int t = 1; t <= n; ++t) {
            int curr_tot = dist_a[t] + dist_b[t] + dist_c[t];
            int common = dist_b[t];
            debug(t, curr_tot, common);
            if (curr_tot <= m) {
                best = min(best, pref2[common] + pref1[curr_tot] - pref1[common]);
            }
        }
        cout << best << "\n";
    }
    return 0;
}

