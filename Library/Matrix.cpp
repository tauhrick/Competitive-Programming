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
