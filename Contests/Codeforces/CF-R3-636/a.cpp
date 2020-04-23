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
        int x;
        for (int in = 3; in <= n; in = (in << 1) | 1) {
            if (n % in == 0) {
                x = n / in;
                break;
            }
        }
        cout << x << "\n";
    }
    return 0;
}

