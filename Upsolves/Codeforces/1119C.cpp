#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (A[i][j] != B[i][j]) {
                A[i][j] ^= 1;
                A[i + 1][j] ^= 1;
                A[i][j + 1] ^= 1;
                A[i + 1][j + 1] ^= 1;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ok = ok && A[i][j] == B[i][j];
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
    return 0;
}

