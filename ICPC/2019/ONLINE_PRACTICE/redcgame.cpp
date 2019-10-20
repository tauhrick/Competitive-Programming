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
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int sum = 0;
  vector<int> o;
  for (int i = 0; i < n; ++i) {
    if (v[i] <= k) {
      sum += v[i];
    } else {
      sum += k;
      o.emplace_back(v[i] - k);
    }
  }
  sort(o.rbegin(), o.rend());
  if (o.size() == 0) {
    cout << sum << "\n";
  } else if (o.size() == 1) {
    cout << sum + o.front() << "\n";
  } else {
    int sum_2 = 0;
    for (int i = 2; i < (int) o.size(); ++i) {
      sum_2 += o[i];
    }
    if (o[1] >= sum_2) {
      cout << sum + o.front() - (o[1] - sum_2) << "\n";
    } else {
      cout << sum + ((o[1] + sum_2) & 1) << "\n";
    }
  }
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
