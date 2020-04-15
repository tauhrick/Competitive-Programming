#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<vector<int>> arrs;
    vector<int> mx;
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = mx.size();
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (mx[mid] >= A[i]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (lo == (int) mx.size()) {
            arrs.emplace_back(vector<int>{A[i]});
            mx.emplace_back(A[i]);
        } else {
            arrs[lo].emplace_back(A[i]);
            mx[lo] = A[i];
        }
    }
    for (auto &v : arrs) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

