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
  vector<int> nums, sgns;
  int prv_sgn = 1;
  int st = 0;
  if (s[0] == '+') {
    st = 1;
  } else if (s[0] == '-') {
    st = 1;
    prv_sgn = -1;
  }
  for (int i = st; i < n; ) {
    assert(s[i] != '-' && s[i] != '+');
    int num = 0;
    while (i < n) {
      if (s[i] == '-' || s[i] == '+') {
        break;
      }
      num = 10 * num + (s[i] - '0');
      ++i;
    }
    nums.emplace_back(num);
    sgns.emplace_back(prv_sgn);
    if (i == n) {
      break;
    } else {
      if (s[i] == '-') {
        prv_sgn = -1;
      } else {
        prv_sgn = 1;
      }
      ++i;
    }
  }
  vector<vector<pair<int, int>>> dp(nums.size(), vector<pair<int, int>>(nums.size()));
  vector<vector<int>> seen(nums.size(), vector<int>(nums.size()));
  function<pair<int, int>(int, int)> solve = [&](int ind, int neg) {
    if (ind == (int) nums.size()) {
      return make_pair(0, 0);
    }
    auto& ans = dp[ind][neg];
    auto& vis = seen[ind][neg];
    if (!vis) {
      vis = true;
      ans = {INT_MAX, INT_MIN};
      int curr = ((neg & 1) ? -1 : 1) * sgns[ind] * nums[ind];
      auto updt = [&](auto nxt) {
        ans.first = min(ans.first, curr + nxt.first);
        ans.second = max(ans.second, curr + nxt.second);
      };
      updt(solve(ind + 1, neg));
      if (sgns[ind] == -1) {
        updt(solve(ind + 1, neg + 1));
      }
      if (neg > 0) {
        updt(solve(ind + 1, neg - 1));
      }
    }
    return ans;
  };
  auto values = solve(1, 0);
  cout << values.second - values.first << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
