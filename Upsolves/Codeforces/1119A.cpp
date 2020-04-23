#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> C(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> C[i];
    }
    int st;
    for (int i = 1; i <= n; ++i) {
        if (C[i] != C[1]) {
            st = i;
            break;
        }
    }
    int en;
    for (int i = n; i >= 1; --i) {
        if (C[i] != C[n]) {
            en = i;
            break;
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (C[i] != C[1]) {
            mx = max(mx, i - 1);
        } else if (st < i) {
            mx = max(mx, i - st);
        }
        if (C[i] != C[n]) {
            mx = max(mx, n - i);
        } else if (en > i) {
            mx = max(mx, en - i);
        }
    }
    cout << mx << "\n";
    return 0;
}

