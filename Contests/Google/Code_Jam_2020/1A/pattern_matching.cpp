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

void run_case() {
    int n;
    cin >> n;
    vector<string> P(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        string t;
        for (auto &ch : s) {
            if (ch == '*' && !t.empty() && t.back() == ch) {
                continue;
            }
            t += ch;
        }
        P[i] = t;
    }
    debug(P);
    string pref;
    vector<int> L(n);
    {
        int ind = -1;
        int len = -1;
        for (int i = 0; i < n; ++i) {
            int curr_len = 0;
            for (int j = 0; j < (int) P[i].size(); ++j) {
                if (P[i][j] == '*') {
                    L[i] = j;
                    break;
                } else {
                    ++curr_len;
                }
            }
            if (curr_len > len) {
                len = curr_len;
                ind = i;
            }
            debug(i, ind, len);
        }
        pref = P[ind].substr(0, len);
        debug(pref);
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < (int) P[i].size(); ++j) {
                if (P[i][j] == '*') {
                    break;
                }
                ok = ok && (pref[j] == P[i][j]);
            }
            if (!ok) {
                cout << "*\n";
                return;
            }
        }
    }
    string suff;
    vector<int> R(n);
    {
        int ind = -1;
        int len = -1;
        for (int i = 0; i < n; ++i) {
            int curr_len = 0;
            for (int j = (int) P[i].size() - 1; j >= 0; --j) {
                if (P[i][j] == '*') {
                    R[i] = j;
                    break;
                } else {
                    ++curr_len;
                }
            }
            if (curr_len > len) {
                len = curr_len;
                ind = i;
            }
            debug(i, ind, len);
        }
        suff = P[ind].substr((int) P[ind].size() - len, len);
        debug(suff);
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            int ctr = len - 1;
            for (int j = (int) P[i].size() - 1; j >= 0; --j) {
                if (P[i][j] == '*') {
                    break;
                }
                ok = ok && (suff[ctr--] == P[i][j]);
            }
            if (!ok) {
                cout << "*\n";
                return;
            }
        }
    }
    cout << pref;
    for (int i = 0; i < n; ++i) {
        for (int j = L[i]; j <= R[i]; ++j) {
            if (P[i][j] != '*') {
                cout << P[i][j];
            }
        }
    }
    cout << suff << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        run_case();
    }
    return 0;
}

