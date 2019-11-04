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

const long long INF = 1e16;

void test_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin() + 1, A.end());
    vector<vector<long long>> dp(n + 1, vector<long long>(4));
    vector<vector<int>> seen(n + 1, vector<int>(4));
    vector<vector<int>> trans(n + 1, vector<int>(4));
    function<long long(int, int)> solve = [&](int ind, int rem) {
        if (ind == 1) {
            if (rem <= 1) {
                return -1LL * A[1].first;
            } else {
                return INF;
            }
        }
        auto &ans = dp[ind][rem];
        auto &vis = seen[ind][rem];
        if (!vis) {
            ans = LLONG_MAX;
            vis = true;
            int to_add = 0;
            if (rem == 3) {
                to_add = A[ind].first;
            }
            auto updt = [&](long long cand, int nxt) {
                if (cand < ans) {
                    ans = cand;
                    trans[ind][rem] = nxt;
                }
            };
            if (rem <= 1) {
                updt(to_add + solve(ind - 1, rem), rem);
                updt(to_add - A[ind].first + solve(ind - 1, 3), 3);
            }
            if (rem >= 1) {
                updt(to_add + solve(ind - 1, rem - 1), rem - 1);
            }
        }
        return ans;
    };
    cout << solve(n, 3) << " ";
    vector<int> team(n + 1, -1);
    int ctr = 1;
    int ind = n, rem = 3;
    while (ind >= 1) {
        team[A[ind].second] = ctr;
        rem = trans[ind][rem];
        --ind;
        if (rem == 3) {
            ++ctr;
        }
    }
    cout << ctr << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << team[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
