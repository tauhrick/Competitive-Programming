#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<pair<int, int>, int> cnt;
    for (int i = 1; i <= n; ++i) {
        string s = to_string(i);
        int st = (s.front() - '0');
        int en = (s.back() - '0');
        ++cnt[{st, en}];
    }
    long long prs = 0;
    for (int i = 1; i <= n; ++i) {
        string s = to_string(i);
        int st = (s.front() - '0');
        int en = (s.back() - '0');
        prs += cnt[{en, st}];
    }
    cout << prs << "\n";
    return 0;
}

