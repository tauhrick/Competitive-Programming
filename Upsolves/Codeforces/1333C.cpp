#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n + 1);
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        pref[i] = pref[i - 1] + A[i];
    }
    map<long long, int> last;
    last[0] = 0;
    int ctr = 0;
    long long tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (last.count(pref[i])) {
            ctr = max(ctr, last[pref[i]] + 1);
        }
        tot += i - ctr;
        last[pref[i]] = i;
    }
    cout << tot << "\n";
    return 0;
}

