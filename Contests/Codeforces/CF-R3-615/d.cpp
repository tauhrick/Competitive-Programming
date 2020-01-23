#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin >> q >> x;
    vector<int> cnt(x);
    set<pair<int, int>> st;
    for (int i = 0; i < x; ++i) {
        st.insert({0, i});
    }
    while (q--) {
        int y;
        cin >> y;
        int ind = y % x;
        st.erase({cnt[ind], ind});
        ++cnt[ind];
        st.insert({cnt[ind], ind});
        auto min_pair = *st.begin();
        cout << x * min_pair.first + min_pair.second << "\n";
    }
    return 0;
}

