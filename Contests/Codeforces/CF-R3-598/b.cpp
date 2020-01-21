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
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int rem = n - 1;
    for (int tar = 1; tar <= n; ) {
        int mn = INT_MAX;
        int pos = -1;
        for (int nxt = tar, done = 0; nxt <= n && done <= rem; ++nxt, ++done) {
            if (v[nxt] < mn) {
                mn = v[nxt];
                pos = nxt;
            }
        }
        rem -= pos - tar;
        int buff = pos;
        while (pos > tar) {
            swap(v[pos], v[pos - 1]);
            --pos;
        }
        if (tar == buff) {
            ++tar;
        } else {
            tar = buff;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << v[i] << " \n"[i == n];
    }
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
