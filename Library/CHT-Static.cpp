struct CHT {
    vector<long long> M;
    vector<long long> C;
    int ptr;

    bool bad(int i1, int i2, int i3) {
        double x13 = (C[i3] - C[i1]) / (1. * (M[i1] - M[i3]));
        double x12 = (C[i2] - C[i1]) / (1. * (M[i1] - M[i2]));
        return x13 <= x12;
    }

    // Slopes should be maintained in order: For max (inc), For min (dec)
    void add(long long m, long long c) {
        M.emplace_back(m);
        C.emplace_back(c);
        while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
            M.erase(M.end() - 2);
            C.erase(C.end() - 2);
        }
    }

    long long eval(int ind, long long x) {
        return M[ind] * x + C[ind];
    }

    long long get(long long x) {
        ptr = min(ptr, (int) M.size() - 1);
        while (ptr + 1 < M.size() && eval(ptr + 1, x) <= eval(ptr, x)) { // <= (min)
            ++ptr;
        }
        return eval(ptr, x);
    }
};
