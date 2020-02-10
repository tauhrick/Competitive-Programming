#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int gg = -1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i == 0) {
            gg = v[i];
        } else {
            gg = __gcd(gg, v[i]);
        }
    }
    cout << gg << "\n";
    return 0;
}

