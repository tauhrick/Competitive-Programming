#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string x;
        cin >> n >> x;
        vector<vector<int>> A(n, vector<int>(2));
        bool is_same = true;
        int m = -1;
        for (int i = 0; i < n; ++i) {
            int tar = x[i] - '0';
            int mx = INT_MAX;
            for (int da = 0; da <= 2; ++da) {
                for (int db = 0; db <= 2; ++db) {
                    if (is_same) {
                        if ((da + db) % 3 == tar && max(da, db) < mx) {
                            A[i][0] = da;
                            A[i][1] = db;
                            mx = max(da, db);
                        }
                    } else {
                        if ((da + db) % 3 == tar && min(da, db) < mx) {
                            A[i][m] = min(da, db);
                            A[i][m ^ 1] = max(da, db);
                            mx = min(da, db);
                        }
                    }
                }
            }
            if (is_same && A[i][0] != A[i][1]) {
                is_same = false;
                if (A[i][0] > A[i][1]) {
                    m = 0;
                } else {
                    m = 1;
                }
            }
        }
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < n; ++i) {
                cout << A[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}

