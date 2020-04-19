#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) {
        cnt += (A[i] > A[i - 1]) && (A[i] > A[i + 1]);
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;
}

