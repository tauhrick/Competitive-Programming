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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> best;
    int total_moves = 0;
    while (true) {
        vector<int> moves;
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i + 1] == 'L' && s[i] == 'R') {
                moves.emplace_back(i);
                swap(s[i], s[i + 1]);
                ++i;
            }
        }
        if (moves.empty()) {
            break;
        } else {
            best.emplace_back(moves);
            total_moves += moves.size();
        }
    }
    if (k < (int) best.size() || k > total_moves) {
        cout << "-1\n";
        return 0;
    }
    debug(best);
    int step = 0;
    int ctr = 0;
    for (int i = k; i >= 1; --i) {
        int take = min((int) best[step].size() - ctr, total_moves - i + 1);
        cout << take << " ";
        for (int j = ctr; j < ctr + take; ++j) {
            cout << best[step][j] + 1 << " ";
        }
        cout << "\n";
        total_moves -= take;
        ctr += take;
        if (ctr == (int) best[step].size()) {
            ++step;
            ctr = 0;
        }
    }
    return 0;
}

