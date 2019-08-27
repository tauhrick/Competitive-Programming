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

bool is_prime(int p) {
  if (p == 1) {
    return false;
  }
  for (int i = 2; i * i <= p; ++i) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}

void test_case() {
  int n;
  cin >> n;
  if (is_prime(n)) {
    cout << "1\n" << n << "\n";
    return;
  } else if (is_prime(n - 2)) {
    cout << "2\n2 " << n - 2 << "\n";
    return;
  }
  vector<int> primes;
  for (int i = 1; i <= 300; ++i) {
    if (is_prime(i)) {
      primes.emplace_back(i);
    }
  }
  map<int, pair<int, int>> data_t;
  for (auto i : primes) {
    for (auto j : primes) {
      data_t[i + j] = {i, j};
    }
  }
  for (int d1 = 0; d1 <= 300; ++d1) {
    int p = n - d1;
    if (is_prime(p) && data_t.count(d1)) {
      cout << "3\n" << p << " " << data_t[d1].first << " " << data_t[d1].second << "\n";
      return;
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
