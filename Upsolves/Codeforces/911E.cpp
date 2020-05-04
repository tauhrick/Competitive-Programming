#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> P(k + 1);
    set<int> done;
    for (int i = 1; i <= k; ++i) {
        cin >> P[i];
        done.insert(P[i]);
    }
    deque<int> S;
    int tar = 1;
    for (int i = 1; i <= k; ++i) {
        S.push_back(P[i]);
        while (!S.empty() && S.back() == tar) {
            S.pop_back();
            ++tar;
        }
    }
    while (!S.empty()) {
        int prv = S.back();
        while (prv > tar) {
            --prv;
            if (done.count(prv)) {
                cout << "-1\n";
                return 0;
            }
            P.emplace_back(prv);
            done.insert(prv);
        }
        tar = S.back() + 1;
        S.pop_back();
    }
    for (int i = n; i >= tar; --i) {
        if (done.count(i)) {
            cout << "-1\n";
            return 0;
        }
        P.emplace_back(i);
        done.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << P[i] << " ";
    }
    cout << "\n";
    return 0;
}

