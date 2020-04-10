#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> mx_fact(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            mx_fact[j] = i;
        }
    }
    sort(mx_fact.begin() + 1, mx_fact.end());
    for (int i = 2; i <= n; ++i) {
        cout << mx_fact[i] << " ";
    }
    cout << "\n";
    return 0;
}

