#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (min({a, b, c}) != 0 && a + b + c == 180) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

