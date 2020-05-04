#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] & 1) {
            ++odd;
        } else {
            ++even;
        }
    }
    int res = min(odd, even);
    odd -= res;
    res += odd / 3;
    cout << res << "\n";
    return 0;
}

