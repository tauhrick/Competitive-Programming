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

const int N = 1e3 + 10;

Mint dp[11][N][N];
int seen[11][N][N];

void test_case() {
    int n, m;
    cin >> n >> m;
    function<Mint(int, int, int)> solve = [&](int ind, int a, int b) {
        if (a > b) {
            return Mint(0);
        } else if (ind == m + 1) {
            return Mint(1);
        }
        auto &ans = dp[ind][a][b];
        auto &vis = seen[ind][a][b];
        if (!vis) {
            vis = true;
            ans += solve(ind, a + 1, b);
            ans += solve(ind, a, b - 1);
            ans -= solve(ind, a + 1, b - 1);
            ans += solve(ind + 1, a, b);
        }
        return ans;
    };
    cout << solve(1, 1, n).get() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
