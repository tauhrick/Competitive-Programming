#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> A(n);
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            int curr_ans = x / A[i];
            if (x % A[i] != 0) {
                if (curr_ans >= 1) {
                    ++curr_ans;
                } else {
                    curr_ans = 2;
                }
            }
            res = min(res, curr_ans);
        }
        cout << res << "\n";
    }
    return 0;
}

