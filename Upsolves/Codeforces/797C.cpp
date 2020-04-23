#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> last(256, -1);
    for (int i = 0; i < n; ++i) {
        last[s[i]] = i;
    }
    string res;
    stack<char> stk;
    int ctr = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (last[ch] == -1) {
            continue;
        }
        while (!stk.empty() && stk.top() <= ch) {
            res += stk.top();
            stk.pop();
        }
        while (ctr <= last[ch]) {
            if (s[ctr] == ch) {
                res += ch;
            } else {
                stk.push(s[ctr]);
            }
            ++ctr;
        }
    }
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    cout << res << "\n";
    return 0;
}

