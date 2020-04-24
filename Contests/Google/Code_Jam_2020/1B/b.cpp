#include <bits/stdc++.h>

using namespace std;

string to_string(char ch) {
    return "'" + string(1, ch) + "'";
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <size_t N>
string to_string(bitset<N> v) {
    return v.to_string();
}

template <typename A>
string to_string(A v) {
    string res = "{", sep;
    for (const auto x : v) {
        res += sep + to_string(x);
        sep = ", ";
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

const int M = 1e9;
const int N = M / 2;
const vector<pair<int, int>> Q = {{0, 0}, {N, N}, {-N, N}, {-N, -N}, {N, -N}};

int A, B;

void test_case() {
    auto ask = [&](int xx, int yy) {
        cout << xx << " " << yy << endl;
        string resp;
        cin >> resp;
        if (resp == "WRONG") {
            exit(0);
        }
        return resp;
    };
    for (auto pp : Q) {
        int x = pp.first;
        int y = pp.second;
        auto resp = ask(x, y);
        debug(x, y, resp);
        if (resp == "CENTER") {
            return;
        } else if (resp == "HIT") {
            int rr;
            { // calc rr
                debug("Right");
                int lo = x, hi = M;
                while (lo < hi) {
                    int mid = lo + (hi - lo + 1 >> 1);
                    auto foo = ask(mid, y);
                    debug(mid, foo);
                    if (foo == "CENTER") {
                        return;
                    } else if (foo == "HIT") {
                        lo = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                rr = lo;
            }
            int ll;
            { // calc ll
                debug("Left");
                int lo = -M, hi = x;
                while (lo < hi) {
                    int mid = lo + (hi - lo >> 1);
                    auto foo = ask(mid, y);
                    debug(mid, foo);
                    if (foo == "CENTER") {
                        return;
                    } else if (foo == "HIT") {
                        hi = mid;
                    } else {
                        lo = mid + 1;
                    }
                }
                ll = lo;
            }
            x = (ll + rr) / 2;
            int dd;
            { // calc dd
                debug("Down");
                int lo = -M, hi = y;
                while (lo < hi) {
                    int mid = lo + (hi - lo >> 1);
                    auto foo = ask(x, mid);
                    debug(mid, foo);
                    if (foo == "CENTER") {
                        return;
                    } else if (foo == "HIT") {
                        hi = mid;
                    } else {
                        lo = mid + 1;
                    }
                }
                dd = lo;
            }
            int uu;
            { // calc uu
                debug("UP");
                int lo = y, hi = M;
                while (lo < hi) {
                    int mid = lo + (hi - lo + 1 >> 1);
                    auto foo = ask(x, mid);
                    debug(mid, foo);
                    if (foo == "CENTER") {
                        return;
                    } else if (foo == "HIT") {
                        lo = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                uu = lo;
            }
            y = (uu + dd) / 2;
            auto foo = ask(x, y);
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc >> A >> B;
    debug(tc, A, B);
    for (int tt = 1; tt <= tc; ++tt) {
        test_case();
    }
    return 0;
}

