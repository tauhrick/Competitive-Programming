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

struct Line {
    long long m, c;
    mutable function<const Line*()> succ;

    bool operator<(const Line &other) const {
        return m > other.m; // > (min)
    }

    bool operator<(const long long &x) const {
        auto *nxt = succ();
        if (!nxt) {
            return 0;
        } else {
            return m * x + c > nxt->m * x + nxt->c; // > (min)
        }
    }
};

struct CHT : public multiset<Line, less<>> {
    bool bad(iterator i2) {
        auto i3 = next(i2);
        if (i2 == begin()) {
            if (i3 == end()) {
                return 0;
            } else {
                return i2->m == i3->m && i2->c >= i3->c; // >= (min)
            }
        } else {
            auto i1 = prev(i2);
            if (i3 == end()) {
                return i2->m == i1->m && i2->c >= i1->c; // >= (min)
            } else {
                return (i3->c - i1->c) * (i1->m - i2->m) <= (i2->c - i1->c) * (i1->m - i3->m); // 
            }
        }
    }

    void add(long long m, long long c) {
        auto it = insert({m, c});
        it->succ = [=] {
            return next(it) == end() ? nullptr : &*next(it);
        };
        if (bad(it)) {
            erase(it);
            return;
        }
        while (next(it) != end() && bad(next(it))) {
            erase(next(it));
        }
        while (it != begin() && bad(prev(it))) {
            erase(prev(it));
        }
    }

    long long get(long long x) {
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }
};

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
    CHT hull;
    for (int i = 1; i < N; ++i) {
        hull.add(valid_rects[i].b, dp[i - 1]);
        dp[i] = hull.get(valid_rects[i].l);
    }
    cout << dp.back() << "\n";
    return 0;
}

