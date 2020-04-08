#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int h, g;
        cin >> h >> g;
        int n = (1 << h) - 1;
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i].first;
            A[i].second = i + 1;
        }
        sort(A.begin(), A.end());
        int safe = (1 << g) - 1;
        vector<bool> filled(n + 1);
        fill(filled.begin() + safe + 1, filled.end(), true);
        vector<bool> removed(n + 1, true);
        long long min_sum = 0;
        for (auto& pp : A) {
            int ind = pp.second;
            while (ind > safe || filled[ind]) {
                ind /= 2;
            }
            if (ind == 0 || !filled[2 * ind] || !filled[2 * ind + 1]) {
                continue;
            } 
            filled[ind] = true;
            removed[pp.second] = false;
            min_sum += pp.first;
        }
        cout << min_sum << "\n";
        for (int i = n; i >= 1; --i) {
            if (removed[i]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

