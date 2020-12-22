struct Gauss {
    static const int bits = 32;
    vector<int> table;

    Gauss() {
        table.assign(bits, 0);
    }

    int size() {
        int ans = 0;
        for (int i = bits - 1; i >= 0; --i) {
            ans += (table[i] != 0);
        }
        return ans;
    }

    bool can(int x) {
        for (int i = bits - 1; i >= 0; --i)  {
            x = min(x, x ^ table[i]);
        }
        return x == 0;
    }

    void add(int x) {
        for (int i = bits - 1; i >= 0; --i) {
            if (table[i] == 0 && (x & (1 << i))) {
                table[i] = x;
                break;
            } else {
                x = min(x, x ^ table[i]);
            }
        }
    }

    int get_best() {
        int x = 0;
        for (int i = bits - 1; i >= 0; --i) {
            x = max(x, x ^ table[i]);
        }
        return x;
    }

    void merge(Gauss& o) {
        for(int i = bits - 1; i >= 0; --i) {
            add(o.table[i]);
        }
    }
};
