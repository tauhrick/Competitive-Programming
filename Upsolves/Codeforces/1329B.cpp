#include <bits/stdc++.h>
using namespace std;

class Modular {
private:
    uint32_t n;
    uint32_t mod;

public:
    Modular(int64_t _n = 0, uint32_t _mod = 1) : n((_n >= 0 ? _n : _mod - (-_n) % _mod) % _mod), mod(_mod) {}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int d, m;
        in >> d >> m;
        Modular answer(0, m);
        Modular prev(0, m);
        int msb = 0;
        while ((1 << msb) <= d) {
            Modular curr = Modular(1, m) + prev;
            Modular cnt(min(1 << msb, d - (1 << msb) + 1), m);
            answer += curr * cnt;
            prev += curr * cnt;
            ++msb;
        }
        cout << answer.get() << "\n";
    }
    return 0;
}

