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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, q;
        cin >> a >> b >> q;
        if (b < a) {
            swap(a, b);
        }
        int lcm = a * b;
        vector<int> da;
        vector<int> db;
        for (int i = 0; i < lcm; ++i) {
            da.emplace_back(i % a);
            db.emplace_back((i % b) % a);
        }
        vector<int> pf(lcm);
        for (int i = 0; i < lcm; ++i) {
            pf[i] = da[i] != db[i];
            if (i - 1 >= 0) {
                pf[i] += pf[i - 1];
            }
        }
        while (q--) {
            long long l, r;
            cin >> l >> r;
            long long diff = r - l + 1;
            int rem = diff % lcm;
            long long cnt = diff / lcm;
            long long res = cnt * pf.back();
            int st = l % lcm;
            int ded = min(rem, lcm - st);
            if (rem) {
                rem -= ded;
                res += pf[st + ded - 1];
                if (st - 1 >= 0) {
                    res -= pf[st - 1];
                }
                if (rem) {
                    res += pf[rem - 1];
                }
            }
            cout << res << " ";
        }
        cout << "\n";
    }
    return 0;
}

