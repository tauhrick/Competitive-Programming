#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> A(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }
    int n;
    cin >> n;
    map<int, int> total_count;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++total_count[x];
    }
    auto check = [&](int r1, int c1, int r2, int c2, int r3, int c3) {
        map<int, int> cnt;
        ++cnt[A[r1][c1]];
        ++cnt[A[r2][c2]];
        ++cnt[A[r3][c3]];
        for (auto &p : cnt) {
            if (!total_count.count(p.first) || total_count[p.first] < p.second) {
                return false;
            }
        }
        return true;
    };
    if (check(0, 0, 0, 1, 0, 2)
        || check(1, 0, 1, 1, 1, 2) 
        || check(2, 0, 2, 1, 2, 2)
        || check(0, 0, 1, 0, 2, 0)
        || check(0, 1, 1, 1, 2, 1)
        || check(0, 2, 1, 2, 2, 2)
        || check(0, 0, 1, 1, 2, 2)
        || check(0, 2, 1, 1, 2, 0)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}

