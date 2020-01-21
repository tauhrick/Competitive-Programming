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
  vector<int> X(n + 1), Y(n + 1), H(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> X[i] >> Y[i] >> H[i];
  }
  for (int x = 0; x <= 100; ++x) {
    for (int y = 0; y <= 100; ++y) {
      set<int> h;
      int mn = INT_MAX;
      for (int i = 1; i <= n; ++i) {
        int dis = abs(x - X[i]) + abs(y - Y[i]);
        if (H[i] > 0) {
          h.insert(H[i] + dis);
        } else {
          mn = min(mn, dis);
        }
      }
      if (h.size() == 1) {
        int height = *h.begin();
        if (height <= mn) {
          cout << x << " " << y << " " << *h.begin() << "\n";
          return;
        }
      } else if (h.size() == 0 && mn == 1) {
        cout << x << " " << y << " " << mn << "\n";
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
