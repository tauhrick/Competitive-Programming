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

bool valid(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int r = 0; r < n; ++r) {
        set<int> rr, cc;
        for (int c = 0; c < n; ++c) {
            rr.emplace(grid[r][c]);
            cc.emplace(grid[c][r]);
        }
        if (rr.size() != n || cc.size() != n) {
            return false;
        }
    }
    return true;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> P(n, vector<int>(n));
    for (int r = 0, st = 0; r < n; ++r) {
        for (int c = 0, i = st; c < n; ++c) {
            P[r][c] = i + 1;
            i = (i + 1) % n;
        }
        st = (st - 1 + n) % n;
    }
    for (int n1 = 1; n1 <= n; ++n1) {
        for (int c1 = 1; c1 <= n; ++c1) {
            for (int n2 = n1; n2 <= n; ++n2) {
                for (int c2 = 1; c2 <= n; ++c2) {
                    if (n2 == n1 + 1 || c1 + c2 >= n) {
                        continue;
                    }
                    int rem_sum = k - n1 * c1 - n2 * c2;
                    int rem_cnt = n - c1 - c2;
                    if (rem_sum < rem_cnt || rem_sum % rem_cnt != 0) {
                        continue;
                    }
                    int n3 = rem_sum / rem_cnt;
                    if (n3 == n1 && n3 == n2 && n2 == n1) {
                    } else if (n3 > n || n3 <= n2 + 1) {
                        continue;
                    }
                    int c3 = rem_cnt;
                    vector<bool> taken(n);
                    vector<vector<int>> grid;
                    for (int r = 0; r < n; ++r) {
                        for (int i = 0; i < n; ++i) {
                            if (taken[i]) {
                                continue;
                            }
                            if (c1) {
                                if (P[i][r] == n1) {
                                    taken[i] = true;
                                    grid.emplace_back(P[i]);
                                    --c1;
                                    break;
                                }
                            } else if (c3) {
                                if (P[i][r] == n3) {
                                    taken[i] = true;
                                    grid.emplace_back(P[i]);
                                    --c3;
                                    break;
                                }
                            } else {
                                if (P[i][r] == n2) {
                                    taken[i] = true;
                                    grid.emplace_back(P[i]);
                                    --c2;
                                    break;
                                }
                            }
                        }
                    }
                    if (!valid(grid)) {
                        assert(false);
                    } else {
                        cout << "POSSIBLE\n";
                        for (int r = 0; r < n; ++r) {
                            for (int c = 0; c < n; ++c) {
                                cout << grid[r][c] << " ";
                            }
                            cout << "\n";
                        }
                        return;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;
}

