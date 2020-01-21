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
  int m = 2 * n;
  vector<int> res(m + 1, -1);
  for (int l = 1, r = n + 1, i = 1, nxt = 1; i <= n; ++l, ++r, ++i) {
    if (i & 1) {
      res[l] = nxt++;
      res[r] = nxt++;
    } else {
      res[r] = nxt++;
      res[l] = nxt++;
    }
  }
  set<long long> unq;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += res[i];
  }
  unq.insert(sum);
  for (int i = 2; i <= m; ++i) {
    sum -= res[i - 1];
    int nxt = i + n - 1;
    if (nxt > m) {
      nxt %= m;
    }
    sum += res[nxt];
    unq.insert(sum);
  }
  if (unq.size() > 2) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 1; i <= m; ++i) {
      cout << res[i] << " \n"[i == m];
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
