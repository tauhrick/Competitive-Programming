#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    vector<int> inds;
    while (l < r) {
        while (l < n && s[l] != '(') {
            ++l;
        }
        while (r >= 0 && s[r] != ')') {
            --r;
        }
        if (l < r) {
            inds.emplace_back(l++);
            inds.emplace_back(r--);
        }
    }
    sort(inds.begin(), inds.end());
    if (inds.empty()) {
        cout << "0\n";
    } else {
        cout << "1\n" << inds.size() << "\n";
        for (auto &ind : inds) {
            cout << ind + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

