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

void test_case() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
       cin >> a[i];
   }
   vector<int> b(n);
   for (int i = 0; i < n; ++i) {
       cin >> b[i];
   }
   vector<int> d(n);
   for (int i = 0; i < n; ++i) {
       d[i] = b[i] - a[i];
       if (d[i] < 0) {
           cout << "NO\n";
           return;
       }
   }
   int i = 0;
   while (i < n && d[i] == 0) {
       ++i;
   }
   int _i = i;
   while (i < n && d[i] == d[_i]) {
       ++i;
   }
   while (i < n && d[i] == 0) {
       ++i;
   }
   if (i == n) {
       cout << "YES\n";
   } else {
       cout << "NO\n";
   }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        test_case();
    }
    return 0;
}
