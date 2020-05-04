#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug/Debug.cpp"
#else
#define debug(...) 42
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }
    vector<int> change(n + 1);
    OrderedSet<int> st;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        change[P[i]] = P[i] > mx;
        mx = max(mx, P[i]);
        int ind = st.order_of_key(P[i]);
        if (ind + 1 == (int) st.size()) {
            --change[*st.find_by_order(ind)];
        }
        st.insert(P[i]);
    }
    int mn = INT_MAX;
    int ind = -1;
    for (int i = 1; i <= n; ++i) {
        if (change[i] < mn) {
            mn = change[i];
            ind = i;
        }
    }
    cout << ind << "\n";
    return 0;
}

