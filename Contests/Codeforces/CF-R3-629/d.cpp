#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> T(n);
        for (int i = 0; i < n; ++i) {
            cin >> T[i];
        }
        vector<int> col(n);
        int c = 0;
        int ind = -1;
        for (int i = 0; i < n; ) {
            int st = i;
            while (i < n && T[i] == T[st]) {
                ++i;
            }
            if (i - st > 1) {
                ind = st;
            }
            for (int j = st; j < i; ++j) {
                col[j] = c;
            }
            if (i == n && T[n - 1] != T[0] && col[n - 1] == col[0]) {
                if (ind == -1) {
                    for (int j = st; j < i; ++j) {
                        col[j] = 2;
                    }
                } else {
                    for (int j = ind + 1; j < n; ++j) {
                        col[j] ^= 1;
                    }
                }
            }
            c ^= 1;
        }
        cout << *max_element(col.begin(), col.end()) + 1 << "\n";
        for (int i = 0; i < n; ++i) {
            cout << col[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

