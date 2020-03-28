#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int q;
    cin >> n >> q;
    map<long long, long long> nxt;
    set<long long> st = {n + 1};
    function<long long(long long)> get_par = [&](auto u) {
        if (!nxt.count(u)) {
            return u;
        } else if (nxt.count(nxt[u])) {
            return nxt[u] = get_par(nxt[u]);
        } else {
            return nxt[u];
        }
    };
    auto get_xor = [&](auto x) {
        switch (x % 4) {
            case 0: return x;
            case 1: return 1LL;
            case 2: return x + 1;
            case 3: return 0LL;
        }
    };
    while (q--) {
        int typ;
        long long x;
        cin >> typ >> x;
        if (typ == 1) {
            nxt[x] = x + 1;
            st.insert(x);
        } else {
            x = get_par(x);
            cout << (get_xor(*st.lower_bound(x) - 1) ^ get_xor(x - 1)) << "\n";
        }
    }
    return 0;
}

