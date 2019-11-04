struct Dsu {
    vector<int> par, sz;

    Dsu(int n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.resize(n + 1, 1);
    }

    int find(int x) {
        return (x == par[x] ? x : par[x] = find(par[x]));
    }

    void merge(int a, int b) {
        a = find(a); 
        b = find(b);
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        sz[a] += sz[b];
        par[b] = a;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }
};
