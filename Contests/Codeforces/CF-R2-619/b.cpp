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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            if (A[i] == -1) {
            } else if (i - 1 >= 1 && A[i - 1] == -1) {
                v.emplace_back(A[i]);
            } else if (i + 1 <= n && A[i + 1] == -1) {
                v.emplace_back(A[i]);
            }
        }
        sort(v.begin(), v.end());
        int avg = v.empty() ? 0 : (v.front() + v.back()) / 2;
        for (int i = 1; i <= n; ++i) {
            if (A[i] == -1) {
                A[i] = avg;
            }
        }
        int min_diff = INT_MIN;
        for (int i = 2; i <= n; ++i) {
            min_diff = max(min_diff, abs(A[i] - A[i - 1]));
        }
        cout << min_diff << " " << avg << "\n";
    }
    return 0;
}

