#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, b;
    cin >> tc >> b;
    for (int tt = 1; tt <= tc; ++tt) {
        vector<int> bits(b, -1);
        int ctr = 0;
        int lim = (b - 1) / 2;
        pair<int, int> pos(-1, -1);
        auto ask = [&](int ind) {
            cout << ind + 1 << endl;
            int x;
            cin >> x;
            return x;
        };
        auto rev = [&](int ind) {
            return b - 1 - ind;
        };
        auto compliment_bits = [&]() {
            for (int i = 0; i < b; ++i) {
                if (bits[i] != -1) {
                    bits[i] ^= 1;
                }
            }
        };
        auto reverse_bits = [&]() {
            reverse(bits.begin(), bits.end());
        };
        for (int quer = 0; quer < 150 && ctr <= lim; quer += 2) {
            if (quer % 10 == 0 && quer != 0) {
                if (pos.first == -1) {
                    int st = ask(pos.second);
                    int en = ask(rev(pos.second));
                    if (st != bits[pos.second]) {
                        compliment_bits();
                    }
                } else if (pos.second == -1) {
                    int st = ask(pos.first);
                    int en = ask(rev(pos.first));
                    if (st != bits[pos.first]) {
                        compliment_bits();
                    }
                } else {
                    int st = ask(pos.first);
                    int en = ask(pos.second);
                    bool b0 = st == bits[pos.first];
                    bool b1 = en == bits[pos.second];
                    if (!b0 && !b1) {
                        compliment_bits();
                    } else if (b0 && !b1) {
                        reverse_bits();
                    } else if (!b0 && b1) {
                        compliment_bits();
                        reverse_bits();
                    }
                }
            } else {
                bits[ctr] = ask(ctr);
                bits[rev(ctr)] = ask(rev(ctr));
                if (bits[ctr] == bits[rev(ctr)]) {
                    pos.first = ctr;
                } else {
                    pos.second = ctr;
                }
                ++ctr;
            }
        }
        for (int i = 0; i < b; ++i) {
            cout << bits[i];
        }
        cout << endl;
        char response;
        cin >> response;
        if (response == 'N') {
            break;
        }
    }
    return 0;
}

