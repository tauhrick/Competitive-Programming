#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> T(k + 1);
    int tot = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> T[i];
        tot += T[i];
    }
    int mx = 0;
    for (int take = 0; take <= n; ++take) {
        int not_take = n - take;
        long long rem_time = m - 1LL * take * tot;
        if (rem_time < 0) {
            continue;
        }
        vector<pair<int, int>> rem;
        for (int sb = 1; sb <= k; ++sb) {
            for (int task = 1; task <= not_take; ++task) {
                rem.emplace_back(T[sb], task);
            }
        }
        sort(rem.begin(), rem.end());
        vector<int> cnt(not_take + 1);
        int curr = take * (k + 1);
        for (int i = 0; i < (int) rem.size(); ++i) {
            auto [tt, task] = rem[i];
            if (cnt[task] + 1 == k) {
                continue;
            } else if (rem_time - tt < 0) {
                break;
            }
            rem_time -= tt;
            ++cnt[task];
            ++curr;
        }
        mx = max(mx, curr);
    }
    cout << mx << "\n";
    return 0;
}

