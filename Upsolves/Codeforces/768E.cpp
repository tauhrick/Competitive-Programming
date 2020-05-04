#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug/Debug.cpp"
#endif

const int MX = 60;
const vector grundy_value = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

void brute() {
    map<pair<int, long long>, int> dp;
    function<int(int, long long)> get = [&](int rem, long long mask) {
        if (rem == 0) {
            return 0;
        }
        pair key = {rem, mask};
        if (!dp.count(key)) {
            vector<bool> fnd(MX + 1);
            for (int take = 1; take <= rem; ++take) {
                if ((mask >> take) & 1) {
                    continue;
                }
                fnd[get(rem - take, mask | (1LL << take))] = true;
            }
            for (int i = 0; i <= MX; ++i) {
                if (!fnd[i]) {
                    dp[key] = i;
                    break;
                }
            }
        }
        return dp[key];
    };
    for (int i = 0; i <= MX; ++i) {
        cout << get(i, 0) << ", ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    /* brute(); */
    int tot_grundy = 0;
    for (auto &s : S) {
        tot_grundy ^= grundy_value[s];
    }
    cout << (tot_grundy == 0 ? "YES" : "NO") << "\n";
    return 0;
}

