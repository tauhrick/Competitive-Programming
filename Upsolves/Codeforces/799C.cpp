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
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<pair<int, int>>> V(2);
    for (int i = 0; i < n; ++i) {
        int b, p;
        char typ;
        cin >> b >> p >> typ;
        if (typ == 'C') {
            if (p <= c) {
                V[0].emplace_back(b, p);
            }
        } else {
            if (p <= d) {
                V[1].emplace_back(b, p);
            }
        }
    }
    sort(V[0].rbegin(), V[0].rend());
    sort(V[1].rbegin(), V[1].rend());
    int mx = !V[0].empty() && !V[1].empty() ? V[0][0].first + V[1][0].first : INT_MIN;
    debug(V);
    auto get = [&](auto &v, int up) {
        if ((int) v.size() < 2) {
            return INT_MIN;
        }
        sort(v.begin(), v.end(), [](auto ll, auto rr) {
            return ll.second < rr.second;
        });
        vector<int> pref(v.size());
        pref[0] = v[0].first;
        for (int i = 1; i < v.size(); ++i) {
            pref[i] = max(pref[i - 1], v[i].first);
        }
        int curr = INT_MIN;
        int l = 0;
        for (int r = v.size() - 1; r >= 0; --r) {
            while (l < r && v[l].second + v[r].second <= up) {
                ++l;
            }
            if (l - 1 >= 0) {
                if (l - 1 < r) {
                    curr = max(curr, v[r].first + pref[l - 1]);
                } else if (r - 1 >= 0) {
                    curr = max(curr, v[r].first + pref[r - 1]);
                }
            }
        }
        return curr;
    };
    mx = max({mx, get(V[0], c), get(V[1], d)});
    if (mx == INT_MIN) {
        mx = 0;
    }
    cout << mx << "\n";
    return 0;
}
