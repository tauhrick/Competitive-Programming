#include <bits/stdc++.h>
using namespace std;

void test() {
    int n, k;
    cin >> n >> k;
    vector<int> M(n);
    for (int i = 0; i < n; ++i) {
        cin >> M[i];
    }
    priority_queue<array<int, 4>> pq;
    for (int i = 0; i < n - 1; ++i) {
        pq.push({M[i + 1] - M[i], 0, i, i + 1});
    }
    while (k--) {
        auto foo = pq.top();
        pq.pop();
        ++foo[1];
        foo[0] = (M[foo[3]] - M[foo[2]] + foo[1]) / (foo[1] + 1);
        pq.push(foo);
    }
    cout << pq.top()[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        cout << "Case #" << tc << ": ";
        test();
    }
    return 0;
}
