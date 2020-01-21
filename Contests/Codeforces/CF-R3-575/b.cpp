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
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  vector<int> res;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    if ((int) res.size() == k - 1) {
      assert(sum == 0);
      for (int j = i; j <= n; ++j) {
        sum += A[j];
      }
      if (sum & 1) {
        res.emplace_back(n);
        cout << "YES\n";
        for (auto i : res) {
          cout << i << " ";
        }
        cout << "\n";
        return;
      } else {
        cout << "NO\n";
        return;
      }
    }
    sum += A[i];
    if (sum & 1) {
      res.emplace_back(i);
      sum = 0;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    test_case();
  }
  return 0;
}
