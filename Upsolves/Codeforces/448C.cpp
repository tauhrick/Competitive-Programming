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
  set<int> st;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    st.insert(A[i]);
  }
  function<int(int, int)> solve = [&](int l, int r) {
    int ans = r - l + 1;
    int mn = *min_element(A.begin() + l, A.begin() + r + 1);
    for (int i = l; i <= r; ++i) {
      A[i] -= mn;
    }
    int other = mn;
    int i = l;
    while (i <= r) {
      while (i <= r && A[i] == 0) {
        ++i;
      }
      int st = i;
      while (i <= r && A[i] > 0) {
        ++i;
      }
      if (st <= r) {
        other += solve(st, i - 1);
      }
    }
    ans = min(ans, other);
    return ans;
  };
  cout << solve(1, n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
