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
    long long n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    int cnt = 0;
    long long mn_fact = LLONG_MAX;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i == 0) {
            ++cnt;
            mn_fact = min(mn_fact, 1LL * i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ++cnt;
        mn_fact = min(mn_fact, n);
    }
    if (cnt >= 2) {
        cout << "1\n";
    } else {
        cout << mn_fact << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
