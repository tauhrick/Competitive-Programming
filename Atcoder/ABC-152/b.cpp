#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << max(stoi(string(a, '0' + b)), stoi(string(b, '0' + a))) << "\n";
    return 0;
}

