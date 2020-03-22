#include <bits/stdc++.h>
using namespace std;

void test() {
    int n, b;
    cin >> n >> b;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int taken = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (taken + A[i] <= b) {
            taken += A[i];
        } else {
            cout << i << "\n";
            return;
        }
    }
    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        cout << "Case #" << tc << ": ";
        test();
    }
    return 0;
}

