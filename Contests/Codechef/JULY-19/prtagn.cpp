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
  int q;
  cin >> q;
  set<int> s, prv;
  int e, o;
  while (q--) {
    int x;
    cin >> x;
    if (!prv.count(x)) {
      for (auto i : prv) {
        prv.insert(i ^ x);
      }
      prv.insert(x);
      vector<int> add;
      for (auto i : s) {
        add.emplace_back(i ^ x);
      }
      for (auto i : add) {
        if (i) {
          s.insert(i);
        }
      }
      s.insert(x);
      e = o = 0;
      for (auto i : s) {
        if (__builtin_popcount(i) & 1) {
          ++o;
        } else {
          ++e;
        }
      }
    }
    cout << e << " " << o << "\n";
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
