#include <bits/stdc++.h>
using namespace std;

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;
vector<int> A;

void test_case() {
    cin >> n >> m;
    A.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    OrderedSet<int> last;
    vector<int> mn(n + 1, -1), mx(n + 1), previous(n + 1);
    for (int i = 1; i <= n; ++i) {
        previous[i] = -i;
        last.insert(previous[i]);
    }
    set<int> done;
    OrderedSet<int> get_big;
    for (int i = 0; i < m; ++i) {
        if (!done.count(A[i])) {
            done.insert(A[i]);
            mn[A[i]] = 1;
            mx[A[i]] = A[i] + get_big.size() - get_big.order_of_key(A[i]);
        } else {
            mx[A[i]] = max(mx[A[i]], 1 + int(last.size() - last.order_of_key(previous[A[i]]) - 1));
        }
        debug(i, mn, mx);
        get_big.insert(A[i]);
        last.erase(previous[A[i]]);
        previous[A[i]] = i;
        last.insert(previous[A[i]]);
    }
    for (int i = 1; i <= n; ++i) {
        if (!done.count(i)) {
            mn[i] = i;
            mx[i] = i + get_big.size() - get_big.order_of_key(i);
        } else {
            mx[i] = max(mx[i], 1 + int(last.size() - last.order_of_key(previous[i]) - 1));
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << mn[i] << " " << mx[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test_case();
    return 0;
}
