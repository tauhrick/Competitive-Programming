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

const int N = 1e6 + 10, LG = log2(N) + 2;

int n;
vector<int> A;
vector<vector<int>> st[2];
vector<int> lg2;

void build() {
    lg2.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        lg2[i] = lg2[i / 2] + 1;
    }
    st[0].assign(LG, vector<int>(n + 1));
    st[1].assign(LG, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        st[0][0][i] = A[i];
        st[1][0][i] = A[i];
    }
    for (int len = 1; len < LG; ++len) {
        for (int i = 1; i + (1 << len) - 1 <= n; ++i) {
            st[0][len][i]= min(st[0][len - 1][i], st[0][len - 1][i + (1 << (len - 1))]);
            st[1][len][i]= max(st[1][len - 1][i], st[1][len - 1][i + (1 << (len - 1))]);
        }
    }
}

int get(int ind, int l, int r) {
    int j = lg2[r - l + 1];
    if (ind == 0) {
        return min(st[ind][j][l], st[ind][j][r - (1 << j) + 1]);
    } else {
        return max(st[ind][j][l], st[ind][j][r - (1 << j) + 1]);
    }
}

void test_case() {
    cin >> n;
    A.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    build();
    long long answer = 0;
    vector<int> previous(*max_element(A.begin(), A.end()) + 1);
    for (int i = 1; i <= n; ++i) {
        for (auto take : {0, 1}) {
            int low = previous[A[i]] + 1, high = i;
            while (low < high) {
                int mid = low + (high - low >> 1);
                if (get(take, mid, i) == A[i]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            int l = i - low + 1;
            low = i, high = n;
            while (low < high) {
                int mid = low + (high - low + 1 >> 1);
                if (get(take, i, mid) == A[i]) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            int r = low - i + 1;
            if (take == 0) {
                answer -= 1LL * A[i] * r * l;
            } else {
                answer += 1LL * A[i] * r * l; 
            }
        }
        previous[A[i]] = i;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
