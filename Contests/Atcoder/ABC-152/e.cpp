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

template <uint32_t mod>
class Modular {
private:
    uint32_t n;

public:
    Modular(int64_t _n = 0) : n((_n >= 0 ? _n : mod - (-_n) % mod) % mod) {}

    uint32_t get() const {
        return n;
    }

    bool operator ==(const Modular& o) const {
        return n == o.n;
    }

    bool operator !=(const Modular& o) const {
        return n != o.n;
    }

    Modular& operator +=(const Modular& o) {
        n += o.n;
        n = (n < mod ? n : n - mod);
        return *this; 
    }

    Modular& operator -=(const Modular& o) {
        n += mod - o.n;
        n = (n < mod ? n : n - mod);
        return *this;
    }

    Modular& operator *=(const Modular& o) {
        n = uint64_t(n) * o.n % mod;
        return *this;
    }

    Modular& operator /=(const Modular& o) {
        return (*this) *= o.inv();
    }

    Modular operator +(const Modular& o) const {
        return Modular(*this) += o;
    }

    Modular operator -(const Modular& o) const {
        return Modular(*this) -= o;
    }

    Modular operator *(const Modular& o) const {
        return Modular(*this) *= o;
    }

    Modular operator /(const Modular& o) const {
        return Modular(*this) /= o;
    }

    Modular pow(uint64_t b) const {
        Modular ans(1), m = Modular(*this);
        while (b) {
            if (b & 1) {
                ans *= m;
            }
            m *= m;
            b >>= 1;
        }
        return ans;
    }

    Modular inv() const {
        int32_t a = n, b = mod, u = 0, v = 1;
        while (a) {
            int32_t t = b / a;
            b -= t * a;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        assert(b == 1);
        return Modular(u);
    }
};

using Mint = Modular<int(1e9 + 7)>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> facts(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int foo = a[i];
        for (int j = 2; 1LL * j * j <= foo; ++j) {
            if (foo % j == 0) {
                int cnt = 0;
                while (foo % j == 0) {
                    foo /= j;
                    ++cnt;
                }
                facts[i].emplace_back(j, cnt);
            }
        }
        if (foo != 1) {
            facts[i].emplace_back(foo, 1);
        }
    }
    map<int, int> cnt;
    for (auto &num : facts) {
        for (auto &p : num) {
            cnt[p.first] = max(cnt[p.first], p.second);
        }
    }
    Mint lcm = 1;
    for (auto &p : cnt) {
        lcm *= Mint(p.first).pow(p.second);
    }
    debug(lcm.get());
    Mint ans;
    for (int i = 0; i < n; ++i) {
        Mint to_add = lcm;
        for (auto &f : facts[i]) {
            to_add /= Mint(f.first).pow(f.second);
        }
        ans += to_add;
        debug(to_add.get());
    }
    cout << ans.get() << "\n";
    return 0;
}

