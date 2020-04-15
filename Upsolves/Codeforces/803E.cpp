#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(2 * k));
    vector<vector<int>> seen(n, vector<int>(2 * k));
    vector<vector<char>> trans(n, vector<char>(2 * k, '#'));
    auto get_diff = [&](char ch) {
        if (ch == 'W') {
            return 1;
        } else if (ch == 'L') {
            return -1;
        } else {
            return 0;
        }
    };
    function<int(int, int)> get = [&](int ind, int diff) {
        if (ind == n) {
            return int(diff == 0 || diff == 2 * k);
        } else if (diff == 0 || diff == 2 * k) {
            return 0;
        }
        auto &ans = dp[ind][diff];
        auto &vis = seen[ind][diff];
        if (!vis) {
            vis = true;
            if (s[ind] == '?') {
                for (auto ch : "WDL") {
                    ans = get(ind + 1, diff + get_diff(ch));
                    if (ans == true) {
                        trans[ind][diff] = ch;
                        break;
                    }
                }
            } else {
                ans = get(ind + 1, diff + get_diff(s[ind]));
            }
        }
        return ans;
    };
    if (get(0, k)) {
        int ind = 0, diff = k;
        while (ind < n) {
            if (s[ind] == '?') {
                s[ind] = trans[ind][diff];
            }
            cout << s[ind];
            diff += get_diff(s[ind]);
            ++ind;
        }
    } else {
        cout << "NO";
    }
    cout << "\n";
    return 0;
}

