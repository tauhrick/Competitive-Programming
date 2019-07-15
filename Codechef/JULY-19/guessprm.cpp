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

int ask(int a) {
  cout << 1 << " " << a << endl;
  int r;
  cin >> r;
  if (r == -1) {
    exit(0);
  }
  return r;
}

void test_case() {
  int a = 5e4;
  int r = ask(a);
  long long div = 1LL * a * a - r;
  vector<int> cand;
  for (int q = 2; 1LL * q * q <= div; ++q) {
    if (div % q == 0) {
      if (q > r) {
        cand.emplace_back(q);
      }
      while (div % q == 0) {
        div /= q;
      }
    }
  }
  if (div > 1 && div > r) {
    cand.emplace_back(div);
  }
  for (int o = a + 1, done = 0; done <= 10000; ++done, ++o) {
    map<int, int> rem;
    for (auto p : cand) {
      rem[(1LL * o * o) % p] = p;
    }
    if (rem.size() == cand.size()) {
      r = ask(o);
      cout << 2 << " " << rem[r] << endl;
      string resp;
      cin >> resp;
      if (resp == "No") {
        exit(0);
      } else {
        return;
      }
    }
  }
  assert(false);
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
