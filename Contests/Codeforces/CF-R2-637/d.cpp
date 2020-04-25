#include <bits/stdc++.h>

using namespace std;

const vector<string> H = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
const int INF = 4e3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> bits(n);
    for (int i = 0; i < n; ++i) {
        cin >> bits[i];
    }
    auto dp = vector(n, vector(k + 1, 0));
    auto seen = vector(n, vector(k + 1, 0));
    auto trans = vector(n, vector(k + 1, -1));
    auto get_diff = [&](int dig, string &s) {
        auto &t = H[dig];
        int diff = 0;
        for (int i = 0; i < 7; ++i) {
            if (s[i] == '1') {
                if (t[i] == '0') {
                    return INF;
                }
            } else {
                diff += t[i] == '1';
            }
        }
        return diff;
    };
    auto diff = vector(n, vector(10, INF));
    for (int i = 0; i < n; ++i) {
        for (int dig = 9; dig >= 0; --dig) {
            diff[i][dig] = get_diff(dig, bits[i]);
        }
    }
    function<int(int, int)> get = [&](int ind, int rem) {
        if (rem < 0) {
            return 0;
        } else if (ind == n) {
            return int(rem == 0);
        }
        auto &ans = dp[ind][rem];
        auto &vis = seen[ind][rem];
        auto &nxt = trans[ind][rem];
        if (!vis) {
            vis = true;
            for (int dig = 9; dig >= 0; --dig) {
                if (get(ind + 1, rem - diff[ind][dig])) {
                    ans = 1;
                    nxt = dig;
                    break;
                }
            }
        }
        return ans;
    };
    if (get(0, k)) {
        int ind = 0;
        int rem = k;
        while (ind != n) {
            int dig = trans[ind][rem];
            cout << dig;
            rem -= diff[ind][dig];
            ++ind;
        }
    } else {
        cout << -1;
    }
    cout << "\n";
    return 0;
}

