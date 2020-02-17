#include <bits/stdc++.h>
using namespace std;

string to_string(char ch) {
    return "'" + string(1, ch) + "'";
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <size_t N>
string to_string(bitset<N> v) {
    return v.to_string();
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < v.size(); ++i) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct CHT {
    vector<long long> M;
    vector<long long> C;
    int ptr;

    bool bad(int i1, int i2, int i3) {
        double x13 = (C[i3] - C[i1]) / (1. * (M[i1] - M[i3]));
        double x12 = (C[i2] - C[i1]) / (1. * (M[i1] - M[i2]));
        return x13 <= x12;
    }

    // Slopes should be maintained in order: For max (inc), For min (dec)
    void add(long long m, long long c) {
        M.emplace_back(m);
        C.emplace_back(c);
        while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
            M.erase(M.end() - 2);
            C.erase(C.end() - 2);
        }
    }

    long long eval(int ind, long long x) {
        return M[ind] * x + C[ind];
    }

    long long get(long long x) {
        ptr = min(ptr, (int) M.size() - 1);
        while (ptr + 1 < M.size() && eval(ptr + 1, x) <= eval(ptr, x)) { // <= (min)
            ++ptr;
        }
        return eval(ptr, x);
    }
};

int n;
vector<CHT> sg_tree;

void modify(int pos, int m, long long c, int tv = 1, int tl = 1, int tr = n) {
    if (tl != tr) {
        int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
        if (pos <= tm) {
            modify(pos, m, c, lc, tl, tm);
        } else {
            modify(pos, m, c, rc, tm + 1, tr);
        }
    }
    sg_tree[tv].add(m, c);
}

long long get_min(int ql, int qr, int x, int tv = 1, int tl = 1, int tr = n) {
    if (qr < tl || tr < ql) {
        return LLONG_MAX;
    } else if (ql <= tl && tr <= qr) {
        return sg_tree[tv].get(x);
    } else {
        int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
        return min(get_min(ql, qr, x, lc, tl, tm), get_min(ql, qr, x, rc, tm + 1, tr));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;	
    cin >> n >> m;
    vector<pair<int, int>> sp(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> sp[i].first >> sp[i].second;
        pos[i] = i;
    }
    sort(pos.begin() + 1, pos.end(), [&](auto a, auto b) {
        return sp[a] < sp[b];
    });
    vector<int> new_pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        new_pos[pos[i]] = i;
    }
    sort(sp.begin() + 1, sp.end());
    sg_tree.resize(4 * n + 8);
    for (int i = 1; i <= n; ++i) {
        modify(i, -2 * sp[i].first, sp[i].second + 1LL * sp[i].first * sp[i].first);
    }
    vector<int> c(m + 1);
    vector<vector<int>> skip(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
        int k;
        cin >> k;
        skip[i].resize(k + 1);
        for (int j = 0; j < k; ++j) {
            cin >> skip[i][j];
            skip[i][j] = new_pos[skip[i][j]];
        }
        skip[i].back() = n + 1;
        sort(skip[i].begin(), skip[i].end());
    }
    vector<int> order(m + 1);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](auto a, auto b) {
        return c[a] < c[b];
    });
    vector<long long> res(m + 1);
    for (int i = 1; i <= m; ++i) {
        int ind = order[i];
        long long min_cost = LLONG_MAX;
        int st = 1;
        for (auto &mark : skip[ind]) {
            int en = mark - 1;
            if (st <= en) {
                min_cost = min(min_cost, get_min(st, en, c[ind]));
            }
            st = en + 2;
        }
        res[ind] = min_cost + 1LL * c[ind] * c[ind];
    }
    for (int i = 1; i <= m; ++i) {
        cout << res[i] << "\n";
    }
    return 0;
}

