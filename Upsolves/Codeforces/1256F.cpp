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

long long get_inversion_count(string &s) {
    long long inv_cnt = 0;
    vector<int> cnt(26);
    for (int i = s.size() - 1; i >= 0; --i) {
        int pos = s[i] - 'a';
        for (int j = 0; j < pos; ++j) {
            inv_cnt += cnt[j];
        }
        ++cnt[pos];
    }
    return inv_cnt;
}

void test_case() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    string sorted_s = s;
    string sorted_t = t;
    sort(sorted_s.begin(), sorted_s.end());
    sort(sorted_t.begin(), sorted_t.end());
    if (sorted_s != sorted_t) {
        cout << "NO\n";
    } else {
        long long inv_s = get_inversion_count(s);
        long long inv_t = get_inversion_count(t);
        if (abs(inv_s - inv_t) % 2 == 0) {
            cout << "YES\n";
        } else {
            for (int i = 0; i + 1 < n; ++i) {
                if (sorted_s[i + 1] == sorted_s[i]) {
                    cout << "YES\n";
                    return;
                }
            }
            cout << "NO\n";
        }
    }
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
}
