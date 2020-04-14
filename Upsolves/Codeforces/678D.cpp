#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Matrix {
    vector<vector<T>> mat;
    int rows, cols;

    Matrix(int n, int m) {
        rows = n;
        cols = m;
        mat.assign(n, vector<T>(m));
    }

    void make_identical() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = i == j;
            }
        }
    }

    Matrix operator+(const Matrix &o) {
        assert(rows == o.rows && cols == o.cols);
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res.mat[i][j] = mat[i][j] + o.mat[i][j];
            }
        }
        return res;
    }

    Matrix operator*(const Matrix &o) {
        assert(cols == o.rows);
        Matrix res(rows, o.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < o.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    res.mat[i][j] += mat[i][k] * o.mat[k][j];
                }
            }
        }
        return res;
    }

    Matrix pow(long long p) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, x;	
    long long n;
    cin >> a >> b >> n >> x;
    Matrix<Mint> B(2, 1);
    B.mat = {
        {x},
        {1}
    };
    Matrix<Mint> T(2, 2);
    T.mat = {
        {a, b},
        {0, 1}
    };
    B = T.pow(n) * B;
    cout << B.mat[0][0].get() << "\n";
    return 0;
}

