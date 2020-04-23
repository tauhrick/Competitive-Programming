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
    int n;
    cin >> n;
    vector<long long> S(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> S[i];
    }
    sort(S.begin() + 1, S.end());
    vector<long long> diff;
    for (int i = 2; i <= n; ++i) {
        diff.emplace_back(S[i] - S[i - 1]);
    }
    sort(diff.begin(), diff.end());
    long long tot = 0;
    vector<long long> suff(diff.size() + 1);
    for (int i = (int) diff.size() - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + diff[i];
        tot += diff[i];
    }
    debug(S);
    debug(diff);
    debug(suff);
    int q;
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        long long len = r - l + 1;
        long long res = n * len;
        int ind = lower_bound(diff.begin(), diff.end(), len) - diff.begin();
        res -= ind * len - (tot - suff[ind]);
        cout << res << " ";
    }
    cout << "\n";
    return 0;
}

