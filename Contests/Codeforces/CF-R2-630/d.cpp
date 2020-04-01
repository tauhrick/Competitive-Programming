#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    const int K = 2e5, LG = log2(K) + 1;
    int mx = (1 << LG) - 1;
    int k;
    cin >> k;
    cout << "3 2\n";
    cout << mx << " " << k << "\n";
    cout << mx - k << " " << mx << "\n";
    cout << "0 " << k << "\n";
    return 0;
}

