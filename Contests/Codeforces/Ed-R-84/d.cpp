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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        vector<int> c(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        vector<vector<int>> cycles;
        vector<int> col(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (col[i] == 0) {
                int u = i;
                while (col[u] == 0) {
                    col[u] = 1;
                    u = p[u];
                }
                if (col[u] == 1) {
                    vector<int> cyc;
                    int v = u;
                    while (col[v] == 1) {
                        cyc.emplace_back(v);
                        col[v] = 2;
                        v = p[v];
                    }
                    cycles.emplace_back(cyc);
                }
                int v = i;
                while (col[v] == 1) {
                    col[v] = 2;
                    v = p[v];
                }
            }
        }
        int mn = INT_MAX;
        for (auto &cyc : cycles) {
            int ln = cyc.size();
            int sq = sqrt(ln);
            auto chk = [&](int x) {
                for (int st = 0; st < x; ++st) {
                    int match = -1;
                    bool ok = true;
                    for (int i = st; i < ln; i += x) {
                        if (match == -1) {
                            match = c[cyc[i]];
                        } else if (c[cyc[i]] != match) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        mn = min(mn, x);
                        break;
                    }
                }
            };
            for (int f = 1; f <= sq; ++f) {
                if (ln % f == 0) {
                    chk(f);
                    if (f != ln / f) {
                        chk(ln / f);
                    }
                }
            }
        }
        cout << mn << "\n";
    }
    return 0;
}

