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

const vector<int> dr = {0, 1, 1, 1, 0, -1, -1, -1};
const vector<int> dc = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
        --T[i];
    }
    set<pair<int, int>> seen;
    set<tuple<int, int, int, int, int>> cache;
    function<void(int, int, int, int, int)> dfs = [&](int r, int c, int dir, int ind, int ctr) {
        if (cache.count({r, c, dir, ind, ctr})) {
            return;
        }
        cache.insert({r, c, dir, ind, ctr});
        seen.insert({r, c});
        if (ctr == T[ind]) {
            if (ind == n - 1) {
                return;
            } else {
                int ll = (dir + 7) % 8;
                int rr = (dir + 1) % 8;
                dfs(r + dr[ll], c + dc[ll], ll, ind + 1, 0);
                dfs(r + dr[rr], c + dc[rr], rr, ind + 1, 0);
            }
        } else {
            dfs(r + dr[dir], c + dc[dir], dir, ind, ctr + 1);
        }
    };
    dfs(0, 0, 0, 0, 0);
    debug(seen);
    cout << seen.size() << "\n";
    return 0;
}

