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
    string s, t;
    cin >> s >> t;
    map<int, int> cnt;
    for (auto ch : s) {
        ++cnt[ch];
    }
    for (auto ch : t) {
        ++cnt[ch];
    }
    for (auto p : cnt) {
        if (p.second & 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    vector<pair<int, int>> swaps;
    auto add = [&](int up, int lo) {
        swap(s[up], t[lo]);
        swaps.emplace_back(up + 1, lo + 1);
    };
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            int ind = -1;
            for (int j = i + 1; j < n; ++j) {
                if (t[j] == t[i]) {
                    ind = j;
                }
            }
            if (ind != -1) {
                add(i, ind);
            } else {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == t[i]) {
                        ind = j;
                    }
                }
                assert(ind != -1);
                add(ind, i + 1);
                add(i, i + 1);
            }
        }
    }
    assert(s == t);
    cout << swaps.size() << "\n";
    for (auto p : swaps) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        test_case();
    }
    return 0;
}
