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
    long long n;
    int q;
    cin >> n >> q;
    set<pair<long long, long long>> prs = {{1, n}};
    set<long long> done;
    auto get_xor = [&](long long ll, long long rr) {
        long long x = 0;
        if (ll & 1) {
            x ^= ll;
            ++ll;
        }
        if (rr % 2 == 0) {
            x ^= rr;
            --rr;
        }
        long long p = (rr - ll + 1) / 2;
        x ^= (p % 2);
        return x;
    };
    while (q--) {
        int typ;
        long long i;
        cin >> typ >> i;
        if (typ == 1) {
            if (done.count(i)) {
                continue;
            }
            done.insert(i);
            auto it = prs.upper_bound({i, LLONG_MAX});
            assert(it != prs.begin());
            --it;
            long long l = (*it).first;
            long long r = (*it).second;
            prs.erase(it);
            if (i - 1 >= l) {
                prs.insert({l, i - 1});
            }
            if (i + 1 <= r) {
                prs.insert({i + 1, r});
            }
        } else {
            long long ans = 0;
            auto it = prs.upper_bound({i, LLONG_MAX});
            if (it != prs.end()) {
                long long l = (*it).first;
                long long r = (*it).second;
                ans = get_xor(l, r);
            }
            if (it != prs.begin()) {
                --it;
                long long l = (*it).first;
                long long r = (*it).second;
                if (l <= i && i <= r) {
                    ans = get_xor(i, r);
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

