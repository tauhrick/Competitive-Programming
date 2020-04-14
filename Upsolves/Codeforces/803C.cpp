#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;	
    cin >> n >> k;
    if (k > 1e6) {
        cout << "-1\n";
        return 0;
    }
    long long best = -1;
    auto check = [&](long long f, bool gen) {
        long long rem = n / f;
        long long curr_sum = (k * (k + 1)) / 2;
        if (curr_sum > rem) {
            return;
        }
        best = max(best, f);
        if (gen) {
            vector<long long> seq(k);
            iota(seq.begin(), seq.end(), 1);
            seq.back() = rem - curr_sum + k;
            for (auto &num : seq) {
                cout << num * f << " ";
            }
        }
    };
    int sq = sqrt(n);
    for (int i = 1; i <= sq; ++i) {
        if (n % i == 0) {
            check(i, false);
            if (i != n / i) {
                check(n / i, false);
            }
        }
    }
    if (best == -1) {
        cout << -1;
    } else {
        check(best, true);
    }
    cout << "\n";
    return 0;
}

