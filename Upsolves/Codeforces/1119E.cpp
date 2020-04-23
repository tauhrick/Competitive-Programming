#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    long long answer = 0;
    long long singles = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        int ded = min(singles, A[i] / 2LL);
        answer += ded;
        singles -= ded;
        A[i] -= 2 * ded;
        answer += A[i] / 3;
        singles += A[i] % 3;
    }
    cout << answer << "\n";
    return 0;
}

