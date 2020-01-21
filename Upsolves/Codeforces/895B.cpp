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
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    long long pairs = 0;
    for (int i = 0; i < n; ++i) {
        int j = (A[i] - 1) / x;
        long long low = 1LL * (j + k) * x;
        long long high = low + x - 1;
        low = max(low, 1LL * A[i]);
        if (high < low) {
            continue;
        }
        int left_ind = lower_bound(A.begin(), A.end(), low) - A.begin();
        int right_ind = upper_bound(A.begin(), A.end(), high) - A.begin();
        --right_ind;
        if (left_ind <= right_ind) {
            pairs += right_ind - left_ind + 1;
        }
    }
    cout << pairs << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
