#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    vector<int> B = {0, 2, 3, 1};
    while (tt--) {
        long long n;
        cin >> n;
        for (int bit = 1; ; bit += 2) {
            long long curr = (1LL << (bit - 1)) + (1LL << bit);
            if (n <= curr) {
                vector<long long> trip(3);
                trip[0] = (1LL << (bit - 1)) + (n - 1) / 3;
                trip[1] = 0;
                for (int i = bit; i >= 0; i -= 2) {
                    int o2 = (trip[0] >> i) & 1;
                    int o1 = (trip[0] >> (i - 1)) & 1;
                    int ind = o2 * 2 + o1;
                    trip[1] = (trip[1] << 2) + B[ind];
                }
                trip[2] = trip[0] ^ trip[1];
                cout << trip[(n - 1) % 3] << "\n";
                break;
            }
            n -= curr;
        }
    }
    return 0;
}

