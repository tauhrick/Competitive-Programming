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
  string s;
  cin >> n >> s;
  vector<vector<int>> pos(10);
  vector<int> cnt(10);
  for (int i = 0; i < n; ++i) {
    int dig = s[i] - '0';
    ++cnt[dig];
    pos[dig].emplace_back(i);
  }
  int req = INT_MAX;
  vector<int> bad;
  for (int i = 0; i < 10; ++i) {
    if (cnt[i] & 1) {
      bad.emplace_back(i);
    }
  }
  if (bad.empty()) {
    cout << "-1\n";
  } else {
    int req = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int dig = s[i] - '0';
      int lo = i, hi = i;
      bool ok = true;
      for (auto er : bad) {
        int up = lower_bound(pos[er].begin(), pos[er].end(), i) - pos[er].begin();
        if (up == pos[er].size()) {
          ok = false;
          break;
        } else {
          hi = max(hi, pos[er][up]);
        }
      }
      if (ok) {
        req = min(req, hi - lo);
      }
    }
    cout << req << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
