#include <bits/stdc++.h>
using namespace std;

struct rect {
    int l, b;

    bool operator<(const rect& other) const {
        if (l != other.l) {
            return l < other.l;
        } else {
            return b < other.b;
        }
    }
};

vector<pair<int, long long>> hull;
int ptr;

bool bad(int i1, int i2, int i3) {
    auto get = [&](int x, int y) {
        return (hull[x].second - hull[i1].second) * (hull[i1].first - hull[y].first);
    };
    return get(i3, i2) <= get(i2, i3);
}

void add_line(int m, long long c) {
    hull.emplace_back(m, c);
    while (hull.size() >= 3 && bad(hull.size() - 3, hull.size() - 2, hull.size() - 1)) {
        hull.erase(hull.end() - 2);
    }
}

long long get_min(int x) {
    auto eval = [&](int ind) {
        return 1LL * hull[ind].first * x + hull[ind].second;
    };
    if (ptr >= hull.size()) {
        ptr = hull.size() - 1;
    }
    while (ptr + 1 < hull.size() && eval(ptr + 1) < eval(ptr)) {
        ++ptr;
    }
    return eval(ptr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;	
    cin >> N;
    vector<rect> rects(N);
    for (int i = 0; i < N; ++i) {
        cin >> rects[i].l >> rects[i].b;
    }
    sort(rects.begin(), rects.end());
    vector<rect> valid_rects(1);
    for (int i = 0; i < N; ++i) {
        while (valid_rects.size() > 1 && valid_rects.back().b <= rects[i].b) {
            valid_rects.pop_back();
        }
        valid_rects.emplace_back(rects[i]);
    }
    N = valid_rects.size();
    vector<long long> dp(N);
    for (int i = 1; i < N; ++i) {
        add_line(valid_rects[i].b, dp[i - 1]);
        dp[i] = get_min(valid_rects[i].l);
    }
    cout << dp.back() << "\n";
    return 0;
}

