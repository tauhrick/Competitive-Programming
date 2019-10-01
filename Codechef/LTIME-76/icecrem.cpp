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
  vector<int> w(n), p(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> p[i] >> v[i];
  }
  vector<pair<long long, long long>> st;
  int mid = (n + 1) / 2;
  for (int mask = 0; mask < (1 << mid); ++mask) {
    long long profit = 0;
    long long ctr = 0;
    bool ok = true;
    for (int i = 0; i < mid; ++i) {
      if (mask & (1 << i)) {
        if (ctr <= w[i]) {
          profit += v[i];
          ctr += p[i];
        } else {
          ok = false;
        }
      }
    }
    if (ok) {
      st.push_back({ctr, profit});
    }
  }
  sort(st.begin(), st.end());
  vector<long long> pref_profit(st.size());
  vector<long long> pref_ctr(st.size());
  pref_profit[0] = st[0].second;
  pref_ctr[0] = st[0].first;
  for (int i = 1; i < st.size(); ++i) {
    pref_profit[i] = max(pref_profit[i - 1], st[i].second);
    pref_ctr[i] = max(pref_ctr[i - 1], st[i].first);
  }
  int rem = n - mid;
  long long best = pref_profit.back();
  for (int mask = 0; mask < (1 << rem); ++mask) {
    long long profit = 0;
    long long p_sum = 0;
    long long up = LLONG_MAX;
    for (int i = mid, j = 0; i < n; ++i, ++j) {
      if (mask & (1 << j)) {
        up = min(up, w[i] - p_sum);
        p_sum += p[i];
        profit += v[i];
      }
    }
    long long ind = upper_bound(pref_ctr.begin(), pref_ctr.end(), up) - pref_ctr.begin();
    --ind;
    if (ind > 0) {
      best = max(best, profit + pref_profit[ind]);
    } else if (up >= 0) {
      best = max(best, profit);
    }
  }
  cout << best << "\n";
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
