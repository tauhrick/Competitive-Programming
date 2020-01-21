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
    string res1 = "{";
    for (const auto &x : v) {
        if (!first) {
            res1 += ", ";
        }
        first = false;
        res1 += to_string(x);
    }
    res1 += "}";
    return res1;
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
    vector<int> A(n + 1);
    vector<vector<int>> G(n + 1);
    auto add_edge = [&](int u, int v) {
        if (u >= 1 && u <= n) {
            G[u].emplace_back(v);
        }
    };
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        add_edge(i + A[i], i);
        add_edge(i - A[i], i);
    }
    auto go = [&](int req, vector<int>& res) {
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; ++i) {
            if ((A[i] % 2) == (req ^ 1)) {
                q.push({i, 0});
            }
        }
        vector<bool> seen(n + 1, false);
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();
            if (seen[u]) {
                continue;
            }
            if ((A[u] % 2) == req) {
                res[u] = d;
            }
            seen[u] = true;
            for (auto& v : G[u]) {
                if (!seen[v]) {
                    q.push({v, d + 1});
                }
            }
        }
    };
    vector<int> res1(n + 1, -1);
    go(0, res1);
    vector<int> res2(n + 1, -1);
    go(1, res2);
    for (int i = 1; i <= n; ++i) {
        if (A[i] & 1) {
            cout << res2[i];
        } else {
            cout << res1[i];
        }
        cout << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
