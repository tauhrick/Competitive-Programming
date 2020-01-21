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

    friend string to_string(Modular &m) {
        return to_string(m.n);
    }
};

using Mint = Modular<int(1e9 + 7)>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int mx = *max_element(A.begin(), A.end());
    vector<int> cnt(mx + 1);
    for (int i = 0; i < n; ++i) {
        ++cnt[A[i]];
    }
    vector<Mint> dp(mx + 1);
    for (int i = mx; i >= 1; --i) {
        int tot = 0;
        for (int j = i; j <= mx; j += i) {
            tot += cnt[j];
        }
        dp[i] = Mint(2).pow(tot) - 1;
        for (int j = i + i; j <= mx; j += i) {
            dp[i] -= dp[j];
        }
    }
    cout << dp[1].get() << "\n";
    return 0;
}

