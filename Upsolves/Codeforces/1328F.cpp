#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;	
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    auto cnt = vector{make_pair(0, 0)};
    for (auto &i : A) {
        if (i == cnt.back().first) {
            ++cnt.back().second;
        } else {
            cnt.emplace_back(i, 1);
        }
    }
    n = cnt.size() - 1;
    cnt.emplace_back(0, 0);
    vector<pair<long long, long long>> prefix(n + 2);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1];
        prefix[i].first += cnt[i].second;
        prefix[i].second += 1LL * cnt[i].first * cnt[i].second;
    }
    vector<pair<long long, long long>> suffix(n + 2);
    for (int i = n; i >= 1; --i) {
        suffix[i] = suffix[i + 1];
        suffix[i].first += cnt[i].second;
        suffix[i].second += 1LL * cnt[i].first * cnt[i].second;
    }
    long long moves = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i].second >= k) {
            moves = 0;
        } else {
            long long req = k - cnt[i].second;
            long long ll = (cnt[i].first - 1) * prefix[i - 1].first - prefix[i - 1].second;
            long long rr = suffix[i + 1].second - (cnt[i].first + 1) * suffix[i + 1].first;
            if (prefix[i - 1].first >= req) {
                moves = min(moves, ll + req);
            }
            if (suffix[i + 1].first >= req) {
                moves = min(moves, rr + req);
            }
            moves = min(moves, ll + rr + req);
        }
    }
    cout << moves << "\n";
    return 0;
}

