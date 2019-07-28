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
  vector<int> X(n);
  for (int i = 0; i < n; ++i) {
    cin >> X[i];
  }
  vector<vector<int>> pos(2);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    --l;
    pos[l].emplace_back(X[i]);
  }
  auto get = [&](int lane) {
    int ctr = 0, prv = INT_MIN;
    while (true) {
      int ob = upper_bound(pos[lane].begin(), pos[lane].end(), ctr) - pos[lane].begin();
      if (ob == (int) pos[lane].size()) {
        ctr = k;
        break;
      }
      int en = pos[lane][ob];
      int o = lane ^ 1;
      int ind = (lower_bound(pos[o].begin(), pos[o].end(), en) - pos[o].begin()) - 1;
      if (ind < 0) {
        ctr = en;
        break;
      }
      int shift = pos[o][ind] + 1;
      if (shift >= ctr && shift < en) {
        int possible = prv + d;
        if (possible < en) {
          ctr = max(possible, shift);
          prv = ctr;
        } else {
          ctr = en;
          break;
        }
      } else {
        ctr = en;
        break;
      }
      lane = o;
    }
    return ctr;
  };
  cout << max(get(0), get(1)) << "\n";
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
