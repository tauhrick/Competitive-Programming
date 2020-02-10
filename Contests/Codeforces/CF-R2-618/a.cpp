#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            if (A[i] == 0) {
                ++A[i];
                ++cnt;
            }
            sum += A[i];
        }
        cnt += (sum == 0);
        cout << cnt << "\n";
    }
    return 0;
}

