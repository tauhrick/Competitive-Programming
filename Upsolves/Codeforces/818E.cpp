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
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<int> primes;
    vector<int> cnts;
    for (int i = 2; 1LL * i * i <= k; ++i) {
        if (k % i == 0) {
            primes.emplace_back(i);
            int cnt = 0;
            while (k % i == 0) {
                ++cnt;
                k /= i;
            }
            cnts.emplace_back(cnt);
        }
    }
    if (k != 1) {
        primes.emplace_back(k);
        cnts.emplace_back(1);
    }
    int P = primes.size();
    auto pf = vector(P, vector(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < P; ++j) {
            pf[j][i] = pf[j][i - 1];
            while (A[i] % primes[j] == 0) {
                A[i] /= primes[j];
                ++pf[j][i];
            }
        }
    }
    long long prs = 0;
    for (int i = 1; i <= n; ++i) {
        auto check = [&](int en) {
            bool ok = true;
            for (int j = 0; j < P; ++j) {
                ok = ok && (pf[j][en] - pf[j][i - 1] >= cnts[j]);
            }
            return ok;
        };
        int lo = i, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (check(lo)) {
            prs += n - lo + 1;
        }
    }
    cout << prs << "\n";
    return 0;
}

