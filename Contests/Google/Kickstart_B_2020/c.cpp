#include <bits/stdc++.h>

using namespace std;

template <uint32_t mod>
class Modular {
private:
    uint32_t n;

public:
    Modular(int64_t _n = 0) : n((_n >= 0 ? _n : mod - (-_n) % mod) % mod) {}

    uint32_t get() const {
        return n;
    }

    bool operator==(const Modular &o) const {
        return n == o.n;
    }

    bool operator!=(const Modular &o) const {
        return n != o.n;
    }

    Modular& operator+=(const Modular &o) {
        n += o.n;
        n = (n < mod ? n : n - mod);
        return *this; 
    }

    Modular& operator-=(const Modular &o) {
        n += mod - o.n;
        n = (n < mod ? n : n - mod);
        return *this;
    }

    Modular& operator*=(const Modular &o) {
        n = uint64_t(n) * o.n % mod;
        return *this;
    }

    Modular& operator/=(const Modular &o) {
        return (*this) *= o.inv();
    }

    Modular operator+(const Modular &o) const {
        return Modular(*this) += o;
    }

    Modular operator-(const Modular &o) const {
        return Modular(*this) -= o;
    }

    Modular operator*(const Modular &o) const {
        return Modular(*this) *= o;
    }

    Modular operator/(const Modular &o) const {
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

    friend string to_string(const Modular &m) {
        return to_string(m.get());
    }
};

using Mint = Modular<int(1e9)>;

const string moves = "NSEW";
const vector<pair<int, int>> D = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void test_case() {
    string s;
    cin >> s;
    int n = s.size();
    Mint dr = 0, dc = 0;
    stack<Mint> stk;
    stk.push(1);
    for (int ind = 0; ind < n; ++ind) {
        if (s[ind] == '(') {
        } else if (s[ind] == ')') {
            stk.pop();
        } else if ('2' <= s[ind] && s[ind] <= '9') {
            int f = s[ind] - '0';
            stk.push(stk.top() * Mint(f));
        } else {
            int j = moves.find(s[ind]);
            dr += Mint(D[j].first) * stk.top();
            dc += Mint(D[j].second) * stk.top();
        }
    }
    cout << dc.get() + 1 << " " << dr.get() + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;
}

