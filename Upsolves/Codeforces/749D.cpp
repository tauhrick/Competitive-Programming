#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<vector<int>> bids(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i];
        bids[A[i]].emplace_back(B[i]);
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (!bids[i].empty()) {
            pq.push({bids[i].back(), i});
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        set<int> L;
        for (int i = 0; i < k; ++i) {
            int l;
            cin >> l;
            L.emplace(l);
        }
        vector<pair<int, int>> erased;
        while (!pq.empty() && L.count(pq.top().second)) {
            erased.emplace_back(pq.top());
            pq.pop();
        }
        if (pq.empty()) {
            cout << "0 0\n";
        } else {
            int a = pq.top().second;
            erased.emplace_back(pq.top());
            pq.pop();
            while (!pq.empty() && L.count(pq.top().second)) {
                erased.emplace_back(pq.top());
                pq.pop();
            }
            if (pq.empty()) {
                cout << a << " " << bids[a][0] << "\n";
            } else {
                int ind = upper_bound(bids[a].begin(), bids[a].end(), pq.top().first) - bids[a].begin();
                cout << a << " " << bids[a][ind] << "\n";
            }
        }
        for (auto &pp : erased) {
            pq.push(pp);
        }
    }
    return 0;
}

