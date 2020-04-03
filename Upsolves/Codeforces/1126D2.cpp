#include <bits/stdc++.h>
using namespace std;

// Returns: [radius in pattern, (start, end) in actual string] for every element
// Actual length of pattern is 2*N - 1 (A_0 * A_1 * ... * A_N)
// Time complexity: O(N)
template <typename T>
vector<pair<int, pair<int, int>>> manacher(T &pattern) {
    int n = pattern.size();
    vector<pair<int, pair<int, int>>> radius(n);
    int center = 0;
    for (int i = 0; i < n; ++i) {
        auto &rad = radius[i].first;
        if (i <= center + radius[center].first) {
            rad = min(radius[center - (i - center)].first, center + radius[center].first - i);
        }
        while (i - rad - 1 >= 0 && i + rad + 1 < n && pattern[i - rad - 1] == pattern[i + rad + 1]) {
            ++rad;
        }
        if (i % 2 == 0) {
            radius[i].second = {i / 2 - rad / 2, i / 2 + rad / 2};
        } else {
            radius[i].second = {i / 2 - (rad + 1) / 2 + 1, i / 2 + (rad + 1) / 2};
        }
        if (i + rad > center + radius[center].first) {
            center = i;
        }
    }
    return radius;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        string t;
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            if (i != s.size() - 1) {
                t += "*";
            }
        }
        auto radius = manacher(t);
        int match = 0;
        while (2 * (match + 1) <= s.size() && s[match] == s[s.size() - match - 1]) {
            ++match;
        }
        int l = 0, r = 0;
        for (int i = 0; i < t.size(); ++i) {
            auto [st, en] = radius[i].second;
            int cut = min(st, (int) s.size() - 1 - en);
            if (cut <= match) {
                if (2 * cut + en - st + 1 > l + r) {
                    if (cut == st) {
                        l = en + 1;
                        r = cut;
                    } else {
                        l = cut;
                        r = s.size() - st;
                    }
                }
            }
        }
        cout << s.substr(0, l) << s.substr(s.size() - r, r) << "\n";
    }
    return 0;
}

