#include <bits/stdc++.h>
using namespace std;

vector<int> M;
vector<long long> C;
int ptr;

bool bad(int i1, int i2, int i3) {
    double lhs = (C[i3] - C[i1]) / (1. * (M[i1] - M[i3]));
    double rhs = (C[i2] - C[i1]) / (1. * (M[i1] - M[i2]));
    return lhs >= rhs;
}

void add(int m, long long c) {
    M.emplace_back(m);
    C.emplace_back(c);
    while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
        M.erase(M.end() - 2);
        C.erase(C.end() - 2);
    }
}

long long eval(int ind, int x) {
    return 1LL * M[ind] * x + C[ind];
}

long long get_max(int x) {
    ptr = min(ptr, (int) M.size() - 1);
    while (ptr + 1 < M.size() && eval(ptr + 1, x) >= eval(ptr, x)) {
        ++ptr;
    }
    return eval(ptr, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int, int, long long>> xya(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        long long a;
        cin >> x >> y >> a;
        xya[i] = {x, y, a};
    }
    sort(xya.begin() + 1, xya.end());
    vector<long long> dp(n + 1);
    add(0, 0);
    for (int i = 1; i <= n; ++i) {
        auto [x, y, a] = xya[i];
        dp[i] = get_max(y) + 1LL * x * y - a;
        add(-x, dp[i]);
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
    return 0;
}

