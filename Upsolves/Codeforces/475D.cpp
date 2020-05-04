#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    const int LG = log2(n) + 2;
    vector<int> A(n);
    auto st_gcd = vector(LG, vector(n, 0));
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        st_gcd[0][i] = A[i];
    }
    for (int k = 1; k < LG; ++k) {
        for (int i = 0; i + (1 << k) - 1 < n; ++i) {
            st_gcd[k][i] = gcd(st_gcd[k - 1][i], st_gcd[k - 1][i + (1 << (k - 1))]);
        }
    }
    map<int, long long> ans;
    for (int i = 0; i < n; ++i) {
        int st = i;
        int target_gcd = A[i];
        while (true) {
            int en = st;
            for (int k = LG - 1; k >= 0; --k) {
                int check = en + (1 << k) - 1;
                if (check < n && gcd(st_gcd[k][en], target_gcd) == target_gcd) {
                    en += (1 << k) - 1;
                }
            }
            ++en;
            ans[target_gcd] += en - st;
            if (en == n) {
                break;
            } else {
                st = en;
                target_gcd = gcd(target_gcd, A[st]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << (ans.count(x) ? ans[x] : 0) << '\n';
    }
    return 0;
}

