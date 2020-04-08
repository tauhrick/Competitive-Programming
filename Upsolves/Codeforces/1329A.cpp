#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> L(m + 1);
    long long tot = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> L[i];
        tot += L[i];
    }
    vector<int> P(m + 1);
    int st = 0;
    int en = 0;
    for (int i = 1; i <= m; ++i) {
        int jmp = max(1LL, 1 + n - (st + tot));
        if (st + jmp > en + 1) {
            cout << "-1\n";
            return 0;
        }
        st += jmp;
        if (st + L[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
        P[i] = st;
        en = max(en, st + L[i] - 1);
        tot -= L[i];
    }
    if (en < n) {
        cout << "-1";
    } else {
        for (int i = 1; i <= m; ++i) {
            cout << P[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}

