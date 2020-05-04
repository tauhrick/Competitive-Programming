#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug/Debug.cpp"
#else
#define debug(...) 42
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> P(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> P[i].first >> P[i].second;
    }
    auto order = [](auto ll, auto rr) {
        if (ll.first == rr.first) {
            return ll.second < rr.second;
        } else {
            return ll.first > rr.first;
        }
    };
    sort(P.begin() + 1, P.end(), order);
    vector<pair<int, int>> I(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> I[i].first >> I[i].second;
    }
    sort(I.begin() + 1, I.end(), order);
    vector<pair<long long, long long>> pf_sum(m + 1);
    for (int i = 1; i <= m; ++i) {
        pf_sum[i] = pf_sum[i - 1];
        pf_sum[i].first += I[i].first;
        pf_sum[i].second += I[i].second;
    }
    long long best = 0;
    long long curr_width = 0;
    long long curr_sig = 0;
    for (int i = 1; i <= n; ++i) {
        if (curr_width + P[i].second > d) {
            break;
        }
        curr_width += P[i].second;
        curr_sig += P[i].first;
        auto ok = [&](int en) {
            return curr_width + pf_sum[en].second <= d;
        };
        int lo = 1, hi = m;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1 >> 1);
            if (ok(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (ok(lo)) {
            best = max(best, curr_sig + pf_sum[lo].first);
        }
    }
    cout << best << "\n";
    return 0;
}

