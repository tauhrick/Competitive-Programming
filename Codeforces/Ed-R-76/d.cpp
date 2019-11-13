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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    int m;
    cin >> m;
    vector<pair<int, int>> p(m + 1);
    vector<int> s(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> p[i].first >> s[i];
        p[i].second = i;
    }
    sort(p.begin() + 1, p.end());
    vector<int> P(m + 1);
    for (int i = 1; i <= m; ++i) {
        P[i] = p[i].first;
    }
    vector<int> S(m + 1);
    for (int i = 1; i <= m; ++i) {
        S[i] = s[p[i].second];
    }
    for (int i = m - 1; i >= 1; --i) {
        S[i] = max(S[i], S[i + 1]);
    }
    int days = 0;
    int ind = 1;
    while (ind <= n) {
        ++days;
        int st = ind;
        int stamina_req = 0;
        int power_req = INT_MIN;
        while (ind <= n) {
           power_req = max(power_req, A[ind]);
           ++stamina_req;
           int i = lower_bound(P.begin() + 1, P.end(), power_req) - P.begin();
           if (i == m + 1) {
               break;
           } else {
               if (S[i] < stamina_req) {
                   break;
               }
               ++ind;
           }
        }
        if (ind == st) {
            cout << "-1\n";
            return;
        }
    }
    cout << days << "\n";
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
