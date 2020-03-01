#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> digits(n + 1, -1);
    for (int i = 1; i <= m; ++i) {
        int s, c;
        cin >> s >> c;
        if (digits[s] == -1) {
            digits[s] = c;
        } else if (digits[s] != c) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (digits[i] == -1) {
            if (n != 1) {
                digits[i] = 1;
            } else {
                digits[i] = 0;
            }
        }
        while (i <= n) {
            if (digits[i] == -1) {
                digits[i] = 0;
            }
            ++i;
        }
    }
    bool all_zero = true;
    for (int i = 1; i <= n; ++i) {
        all_zero = all_zero && (digits[i] == 0);
    }
    if (all_zero && n > 1) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cout << digits[i];
    }
    cout << "\n";
    return 0;
}

