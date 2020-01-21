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
    vector<long long> v(3);
    for (auto& i : v) {
        cin >> i;
    }
    long long res = LLONG_MAX;
    for (int a1 = -1; a1 <= 1; ++a1) {
        for (int a2 = -1; a2 <= 1; ++a2) {
            for (int a3 = -1; a3 <= 1; ++a3) {
                long long x = v[0] + a1;
                long long y = v[1] + a2;
                long long z = v[2] + a3;
                res = min(res, abs(y - x) + abs(z - x) + abs(z - y));
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        test_case();
    }
    return 0;
}
