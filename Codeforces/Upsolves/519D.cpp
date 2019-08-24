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
  vector<int> X(26);
  for (int i = 0; i < 26; ++i) {
    cin >> X[i];
  }
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  vector<long long> pre(n + 1);
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + X[s[i] - 'a'];
  }
  vector<int> prv(26, -1);
  vector<vector<long long>> vecs(26);
  for (int i = 1; i <= n; ++i) {
    int ind = s[i] - 'a';
    if (prv[ind] != -1) {
      vecs[ind].emplace_back(pre[i - 1] - pre[prv[ind]]);
    }
    prv[ind] = i;
  }
  long long res = 0;
  for (int j = 0; j < 26; ++j) {
    auto& v = vecs[j];
    int sz = 2 * v.size() + 1;
    vector<long long> u = {-1, X[j]};
    for (auto i : v) {
      u.emplace_back(i);
      u.emplace_back(X[j]);
    }
    vector<long long> sum(sz + 1);
    map<long long, int> cnt;
    for (int i = 1; i <= sz; ++i) {
      sum[i] = sum[i - 1] + u[i];
      if (i % 2 == 0) {
        ++cnt[sum[i]];
      }
    }
    for (int i = 2; i <= sz; i += 2) {
      res += cnt[sum[i - 1]];
      --cnt[sum[i]];
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
