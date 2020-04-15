#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p;	
    cin >> n >> k >> p;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<int> B(k);
    for (int i = 0; i < k; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int min_cost = INT_MAX;
    for (int st = 0; st <= k - n; ++st) {
        int curr_cost = INT_MIN;
        for (int i = 0; i < n; ++i) {
            curr_cost = max(curr_cost, abs(A[i] - B[st + i]) + abs(B[st + i] - p));
        }
        min_cost = min(min_cost, curr_cost);
    }
    cout << min_cost << "\n";
    return 0;
}

