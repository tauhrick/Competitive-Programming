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

const int N = 32;

long long dp[N][2][2];

long long solve(int bit, int less_l, int less_r, int l, int r) {
    if (bit == -1) {
        return 1;
    }
    auto &ans = dp[bit][less_l][less_r];
    if (ans == -1) {
        ans = 0;
        int bit_l = (l & (1 << bit)) > 0;
        int bit_r = (r & (1 << bit)) > 0;
        int up_l = bit_l;
        int up_r = bit_r;
        if (less_l) {
            up_l = 1;
        }
        if (less_r) {
            up_r = 1;
        }
        for (int i = 0; i <= up_l; ++i) {
            for (int j = 0; j <= up_r; ++j) {
                if ((i + j) != (i ^ j)) {
                    continue;
                }
                ans += solve(bit - 1, less_l | (i < bit_l), less_r | (j < bit_r), l, r);
            }
        }
    }
    return ans;
}

long long solve(int l, int r) {
    if (l < 0 || r < 0) {
        return 0;
    }
    memset(dp, -1, sizeof dp);
    return solve(31, 0, 0, l, r);
}

void test_case() {
    int l, r;
    cin >> l >> r;
    cout << solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1) << "\n";
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

