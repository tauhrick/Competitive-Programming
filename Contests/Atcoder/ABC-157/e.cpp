#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Fenwick {
public:
    vector<T> Fenw;
    int n;

    Fenwick(int _n) : n(_n) {
        Fenw.resize(n);
    }

    void modify(int x, T v) {
        while (x < n) {
            Fenw[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {
        T v{};
        while (x >= 0) {
            v += Fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<Fenwick<int>> cnt(26, Fenwick<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a'].modify(i + 1, 1);
    }
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int i;
            char c;
            cin >> i >> c;
            cnt[s[i - 1] - 'a'].modify(i, -1);
            s[i - 1] = c;
            cnt[s[i - 1] - 'a'].modify(i, 1);
        } else {
            int l, r;
            cin >> l >> r;
            int total = 0;
            for (auto &f : cnt) {
                total += (f.get(r) - f.get(l - 1) > 0);
            }
            cout << total << "\n";
        }
    }
    return 0;
}

