#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<int> pre(n + 2);
    vector<int> suff(n + 2);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] | A[i];
    }
    for (int i = n; i >= 1; --i) {
        suff[i] = suff[i + 1] | A[i];
    }
    int ind = -1;
    int mx = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int o = pre[i - 1] | suff[i + 1];
        int curr = (A[i] | o) - o;
        if (curr > mx) {
            mx = curr;
            ind = i;
        }
    }
    cout << A[ind] << " ";
    for (int i = 1; i <= n; ++i) {
        if (i == ind) {
            continue;
        }
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}

