#include <bits/stdc++.h>
using namespace std;

vector<int> M;
vector<long long> C;
int ptr;

bool bad(int i1, int i2, int i3) {
    double x13 = (C[i3] - C[i1]) / (1. * (M[i1] - M[i3]));
    double x12 = (C[i2] - C[i1]) / (1. * (M[i1] - M[i2]));
    return x13 <= x12;
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

long long get_min(int x) {
    ptr = min(ptr, (int) M.size() - 1);
    while (ptr + 1 < M.size() && eval(ptr + 1, x) <= eval(ptr, x)) {
        ++ptr;
    }
    return eval(ptr, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    vector<long long> dp(n + 1);
    add(b[1], dp[1]);
    for (int i = 2; i <= n; ++i) {
        dp[i] = get_min(a[i]);
        add(b[i], dp[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}

