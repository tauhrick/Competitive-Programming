#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    string b;
    cin >> a >> b;
    int na = a.size();
    int nb = b.size();
    vector<int> suff(nb, -1);
    for (int i = nb - 1, ca = na - 1; i >= 0; --i) {
        while (ca >= 0 && a[ca] != b[i]) {
            --ca;
        }
        if (ca >= 0) {
            suff[i] = ca--;
        }
    }
    int r = 0;
    while (r < nb && suff[r] == -1) {
        ++r;
    }
    int ll = 0, rr = nb - r;
    for (int i = 0, ca = 0; i < nb; ++i) {
        while (ca < na && a[ca] != b[i]) {
            ++ca;
        }
        if (ca < na) {
            r = max(r, i + 1);
            while (r < nb && suff[r] <= ca) {
                ++r;
            }
            if (i + 1 + nb - r > ll + rr) {
                ll = i + 1;
                rr = nb - r;
            }
            ++ca;
        }
    }
    string best = "-";
    if (ll + rr > 0) {
        best = b.substr(0, ll) + b.substr(nb - rr);
    }
    cout << best << "\n";
    return 0;
}

