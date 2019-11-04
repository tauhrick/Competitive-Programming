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
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }
    vector<int> C(n + 1);
    set<pair<int, int>> st;
    for (int i = 1; i <= n; ++i) {
        cin >> C[i];
        st.insert({C[i], i});
    }
    vector<int> K(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> K[i];
    }
    auto get_cost = [&](int u, int v) {
        return 1LL * (K[u] + K[v]) * (abs(pos[u].first - pos[v].first) + abs(pos[u].second - pos[v].second));
    };
    long long cost = 0;
    vector<int> roots;
    vector<int> par(n + 1, -1);
    vector<bool> done(n + 1);
    while (!st.empty()) {
        auto [c, u] = *st.begin();
        st.erase(st.begin());
        cost += c;
        done[u] = true;
        if (par[u] == -1) {
            roots.emplace_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (i != u) {
                long long updt = get_cost(i, u);
                if (!done[i] && updt < C[i]) {
                    st.erase({C[i], i});
                    C[i] = updt;
                    st.insert({C[i], i});
                    par[i] = u;
                }
            }
        }
    }
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; ++i) {
        if (par[i] >= 1) {
            edges.emplace_back(min(i, par[i]), max(i, par[i]));
        }
    }
    cout << cost << "\n";
    cout << roots.size() << "\n";
    for (auto root : roots) {
        cout << root << " ";
    }
    cout << "\n";
    cout << edges.size() << "\n";
    for (auto e : edges) {
        cout << e.first << " " << e.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
