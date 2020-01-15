template <typename A>
vector<int> manacher(A v, int st, int en, int parity) {
    int rev_parity = parity ^ 1;
    vector<int> d(v.size(), -1);
    for (int i = st, l = st, r = st - 1; i <= en; ++i) {
        int ans = (i <= r) ? min(d[l + r - i - rev_parity], r - i + parity) : parity;
        int curr_l = i - ans + 1;
        int curr_r = i + ans - parity;
        while (st <= curr_l - 1 && curr_r + 1 <= en && v[curr_l - 1] == v[curr_r + 1]) {
            ++ans, --curr_l, ++curr_r;
        }
        d[i] = ans;
        if (curr_r > r) {
            l = curr_l, r = curr_r;
        }
    }
    return d;
}
