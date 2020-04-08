#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    int res = 0;
    for (auto i : A) {
        int foo = 2 * i;
        while (true) {
            int ind = lower_bound(A.begin(), A.end(), foo) - A.begin();
            --ind;
            if (ind >= 0) {
                res = max(res, i - (foo - A[ind]));
            }
            if (foo > MX) {
                break;
            }
            foo += i;
        }
    }
    cout << res << "\n";
    return 0;
}

