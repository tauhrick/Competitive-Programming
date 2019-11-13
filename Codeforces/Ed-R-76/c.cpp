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
    vector<int> v(n + 1);
    vector<vector<int>> pos(n + 1);
    int best = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (!pos[v[i]].empty()) {
            best = min(best, i - pos[v[i]].back() + 1);
        }
        pos[v[i]].emplace_back(i);
    }
    if (best == INT_MAX) {
        best = -1;
    }
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        test_case();
    }
    return 0;
}
