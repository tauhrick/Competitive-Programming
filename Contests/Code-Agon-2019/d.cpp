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
  int n, k;
  cin >> n >> k;
  vector<int> A(n + 1);
  vector<pair<long long, int>> nums;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    if (A[i] % k == 0) {
      while (true) {
        nums.emplace_back(A[i], i);
        if (A[i] % k != 0) {
          break;
        }
        A[i] /= k;
      }
    } else {
      nums.emplace_back(A[i], i);
      nums.emplace_back(1LL * A[i] * k, i);
    }
  }
  sort(nums.begin(), nums.end());
  map<int, int> cnt;
  map<long long, int> unq;
  int l = 0, r = 0;
  long long res = LLONG_MAX;
  while (l < (int) nums.size()) {
    while (cnt.size() != n && r < (int) nums.size()) {
      ++cnt[nums[r].second];
      ++unq[nums[r].first];
      ++r;
    }
    if (cnt.size() == n) {
      res = min(res, (*(--unq.end())).first - (*(unq.begin())).first);
    }
    --cnt[nums[l].second];
    if (cnt[nums[l].second] == 0) {
      cnt.erase(nums[l].second);
    }
    --unq[nums[l].first];
    if (unq[nums[l].first] == 0) {
      unq.erase(nums[l].first);
    }
    ++l;
  }
  cout << res << "\n";
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
