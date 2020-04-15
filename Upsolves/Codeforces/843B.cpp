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

const int N = 1e3, Q = 1999;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, start, x;
    cin >> n >> start >> x;
    vector<int> ask = {start};
    for (int i = 1; i <= n; ++i) {
        if (i == start) {
            continue;
        }
        ask.emplace_back(i);
    }
    shuffle(ask.begin() + 1, ask.end(), rng);
    int en = min(n, N);
    int closest_ind = start;
    int closest_val = INT_MIN;
    for (int i = 0; i < en; ++i) {
        cout << "? " << ask[i] << endl;
        int val, nxt;
        cin >> val >> nxt;
        if (val < x && val > closest_val) {
            closest_ind = ask[i];
            closest_val = val;
        }
    }
    int queries = en;
    while (closest_ind != -1 && queries < Q) {
        ++queries;
        cout << "? " << closest_ind << endl;
        int val, nxt;
        cin >> val >> nxt;
        if (val >= x) {
            cout << "! " << val << endl;
            return 0;
        }
        closest_ind = nxt;
    }
    cout << "! -1" << endl;
    return 0;
}

