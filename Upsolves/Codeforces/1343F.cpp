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
        vector<set<int>> seqs(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            int k;
            cin >> k;
            while (k--) {
                int x;
                cin >> x;
                seqs[i].insert(x);
            }
        }
        for (int st = 1; st <= n; ++st) {
            auto cpy = seqs;
            vector<int> P = {st};
            while ((int) P.size() != n) {
                for (auto &seq : cpy) {
                    seq.erase(P.back());
                }
                vector<int> singles;
                for (int i = 0; i < n - 1; ++i) {
                    if ((int) cpy[i].size() == 1) {
                        singles.emplace_back(i);
                    }
                }
                if ((int) singles.size() != 1) {
                    break;
                }
                P.emplace_back(*cpy[singles[0]].begin());
            }
            if ((int) P.size() == n) {
                set<set<int>> rem(seqs.begin(), seqs.end());
                for (int i = 1; i < n; ++i) {
                    set<int> prv = {P[i]};
                    for (int j = i - 1; j >= 0; --j) {
                        prv.insert(P[j]);
                        if (rem.count(prv)) {
                            rem.erase(prv);
                            break;
                        }
                    }
                }
                if (rem.empty()) {
                    for (int i = 0; i < n; ++i) {
                        cout << P[i] << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

