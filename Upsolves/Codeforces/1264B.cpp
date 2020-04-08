#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> C(4);
    for (int i = 0; i < 4; ++i) {
        cin >> C[i];
    }
    bool start_3 = false;
    bool start_1 = false;
    vector<int> res;
    int turn = 0;
    while (*max_element(C.begin(), C.end()) != 0) {
        if (turn % 2 == 0) {
            if (C[2] > 0) {
                res.emplace_back(2);
                --C[2];
            } else if (C[0] > 0) {
                res.emplace_back(0);
                --C[0];
            } else if (!start_3 && !start_1) {
                if (C[3] > 0) {
                    start_3 = true;
                    --C[3];
                } else if (C[1] > 0) {
                    start_1 = true;
                    --C[1];
                }
            } else {
                cout << "NO\n";
                return 0;
            }
        } else {
            if (C[3] > 0) {
                if (res.empty() || res[0] != 2) {
                    cout << "NO\n";
                    return 0;
                } else if (C[2] > 0) {
                    res.emplace_back(3);
                    --C[3];
                } else if (!start_3) {
                    start_3 = true;
                    --C[3];
                    turn ^= 1;
                } else if (C[1] == 0 && C[0] == 0) {
                    res.emplace_back(3);
                    --C[3];
                } else {
                    cout << "NO\n";
                    return 0;
                }
            } else if (C[1] > 0 && !start_1 && !res.empty()) {
                res.emplace_back(1);
                --C[1];
            } else {
                cout << "NO\n";
                return 0;
            }
        }
        turn ^= 1;
    }
    cout << "YES\n";
    if (start_3) {
        cout << "3 ";
    } else if (start_1) {
        cout << "1 ";
    }
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

