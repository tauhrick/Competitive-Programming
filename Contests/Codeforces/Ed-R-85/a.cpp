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
        vector<pair<int, int>> pc(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            cin >> pc[i].first >> pc[i].second;
            ok = ok && (pc[i].first >= pc[i].second);
            if (i != 0) {
                ok = ok && (pc[i].first - pc[i - 1].first >= pc[i].second - pc[i - 1].second);
                ok = ok && pc[i].first >= pc[i - 1].first && pc[i].second >= pc[i - 1].second;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

