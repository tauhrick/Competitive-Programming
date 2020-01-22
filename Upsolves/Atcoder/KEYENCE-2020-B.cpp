#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        int x, l;
        cin >> x >> l;
        ranges[i] = {x - l, x + l};
    }
    sort(ranges.begin(), ranges.end(), [](auto a, auto b) {
        return a.second < b.second;
    });
    int taken = 0;
    int r = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (ranges[i].first >= r) {
            ++taken;
            r = ranges[i].second;
        }
    }
    cout << taken << "\n";
    return 0;
}

