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

using Mint = Modular<int(1e9 + 7)>;

template <typename T>
struct Matrix {
    vector<vector<T>> arr;
    int rows, cols;

    Matrix(int n, int m) {
        rows = n;
        cols = m;
        arr.assign(n, vector<T>(m));
    }

    void make_identical() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == j) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = 0;
                }
            }
        }
    }

    Matrix operator +(const Matrix &o) {
        assert(rows == o.rows && cols == o.cols);
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res.arr[i][j] = arr[i][j] + o.arr[i][j];
            }
        }
        return res;
    }

    Matrix operator *(const Matrix &o) {
        assert(cols == o.rows);
        Matrix res(rows, o.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < o.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    res.arr[i][j] += arr[i][k] * o.arr[k][j];
                }
            }
        }
        return res;
    }

    Matrix power(long long p) {
        assert(rows == cols);
        Matrix o = (*this);
        Matrix res(rows, cols);
        res.make_identical();
        while (p) {
            if (p & 1) {
                res = res * o;
            }
            o = o * o;
            p >>= 1;
        }
        return res;
    }
};

void test_case() {
    vector<long long> v(5);
    for (auto &i : v) {
        cin >> i;
    }
    long long n;
    cin >> n;
    if (n <= 4) {
        cout << n << "\n";
        return;
    }
    Matrix<Mint> T(5, 5);
    T.arr = {
        {v[0], v[1], v[2], v[3], v[4]},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
    };
    Matrix<Mint> B(5, 1);
    B.arr = {
        {4},
        {3},
        {2},
        {1},
        {1}
    };
    Matrix<Mint> R = T.power(n - 4) * B;
    cout << R.arr[0][0].get() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        test_case();
    }
    return 0;
}

