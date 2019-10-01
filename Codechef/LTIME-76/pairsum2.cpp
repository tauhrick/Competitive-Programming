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
  int n, quer;
  cin >> n >> quer;
  vector<int> b(n);
  for (int i = 1; i < n; ++i) {
    cin >> b[i];
  }
  vector<long long> odd(n), even(n);
  for (int i = 1; i < n; ++i) {
    odd[i] = odd[i - 1];
    even[i] = even[i - 1];
    if (i & 1) {
      odd[i] += b[i];
    } else {
      even[i] += b[i];
    }
  }
  while (quer--) {
    int p, q;
    cin >> p >> q;
    if ((q - p) & 1) {
      if (p & 1) {
        cout << (odd[q - 1] - odd[p - 1]) - (even[q - 1] - even[p - 1]) << "\n";
      } else {
        cout << -1 * (odd[q - 1] - odd[p - 1]) + (even[q - 1] - even[p - 1]) << "\n";
      }
    } else {
      cout << "UNKNOWN\n";
    }
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
