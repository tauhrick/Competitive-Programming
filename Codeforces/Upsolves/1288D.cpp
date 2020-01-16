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

int n, m;
vector<vector<int>> A;

pair<int, int> get(int lower_limit) {
    vector<int> location(1 << m);
    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int j = 0; j < m; ++j) {
            mask |= (1 << j) * (A[i][j] >= lower_limit);
        }
        location[mask] = i + 1;
    }
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < (1 << m); ++j) {
            if ((i | j) == (1 << m) - 1 && location[i] && location[j]) {
                return {location[i], location[j]};
            }
        }
    }
    return {0, 0};
}

void test_case() {
    cin >> n >> m;
    A.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    int low = 0, high = 1e9;
    while (low < high) {
        int mid = low + (high - low + 1 >> 1);
        if (get(mid).first > 0) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    pair<int, int> answer = get(low);
    cout << answer.first << " " << answer.second << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
