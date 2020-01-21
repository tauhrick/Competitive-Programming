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

const long long INF = 1e10;

void test_case() {
    string s, t;
    cin >> s >> t;
    s += '$';
    t += '$';
    int len_s = s.size();
    int len_t = t.size();
    vector<vector<vector<long long>>> dp(len_s, vector<vector<long long>>(len_t, vector<long long>(len_s + len_t, -1)));
    vector<vector<vector<long long>>> trans(len_s, vector<vector<long long>>(len_t, vector<long long>(len_s + len_t, -1)));
    function<long long(int, int, int)> solve = [&](int ctr_s, int ctr_t, int tot) {
        if (ctr_s == len_s && ctr_t == len_t) {
            return 1LL * tot;
        } else if (ctr_s == len_s || ctr_t == len_t) {
            return INF;
        }
        auto& ans = dp[ctr_s][ctr_t][tot];
        auto& move = trans[ctr_s][ctr_t][tot];
        if (ans == -1) {
            ans = LLONG_MAX;
            auto updt = [&](int add_s, int add_t, int m) {
                int _tot = tot;
                int extra = 0;
                auto add_char = [&](char ch) {
                    if (ch == '(') {
                        ++_tot;
                    } else if (ch == ')') {
                        --_tot;
                    }
                    if (_tot < 0) {
                        ++extra;
                        ++_tot;
                    }
                };
                if (add_s) {
                    add_char(s[ctr_s]);
                } else {
                    add_char(t[ctr_t]);
                }
                long long _ans = 1 + extra + solve(ctr_s + add_s, ctr_t + add_t, _tot);
                if (_ans < ans) {
                    ans = _ans;
                    move = m;
                }
            };
            if (s[ctr_s] == t[ctr_t]) {
                updt(1, 1, 0);
            } else {
                updt(1, 0, 1);
                updt(0, 1, 2);
            }
        }
        return ans;
    };
    solve(0, 0, 0);
    int _s = 0, _t = 0, _tot = 0;
    string res;
    auto add = [&](char ch) {
        if (ch == '(') {
            ++_tot;
        } else if (ch == ')') {
            --_tot;
            if (_tot < 0) {
                res += '(';
                ++_tot;
            }
        }
        if (ch != '$') {
            res += ch;
        }
    };
    while (_s < len_s && _t < len_t) {
        int move = trans[_s][_t][_tot];
        if (s[_s] == t[_t]) {
            add(s[_s]);
            ++_s;
            ++_t;
        } else if (move == 1) {
            add(s[_s++]);
        } else {
            add(t[_t++]);
        }
    }
    while (_tot > 0) {
        add(')');
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
