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
  int n, k, d;
  cin >> n >> k >> d;
  vector<vector<int>> res;
  vector<int> curr(d, 1);
  function<void(int)> add = [&](int ind) {
    if (ind == d) {
      cout << "-1\n";
      exit(0);
    }
    if (curr[ind] < k) {
      ++curr[ind];
    } else {
      curr[ind] = 1;
      add(ind + 1);
    }
  };
  for (int col = 1; col <= n; ++col) {
    res.emplace_back(curr);
    if (col != n) {
      add(0);
    }
  }
  for (int r = 0; r < d; ++r) {
    for (int c = 0; c < n; ++c) {
      cout << res[c][r] << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
