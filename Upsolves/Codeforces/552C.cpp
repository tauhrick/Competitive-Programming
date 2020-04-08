#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w, m;
    cin >> w >> m;
    while (m != 0) {
        int pp = m % w;
        if (pp != 0) {
            if (pp == w - 1) {
                if (m <= w) {
                    break;
                } else {
                    m += 1;
                }
            } else if (pp != 1) {
                cout << "NO\n";
                return 0;
            }
        }
        m /= w;
    }
    cout << "YES\n";
    return 0;
}

