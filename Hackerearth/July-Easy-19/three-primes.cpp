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

vector<int> sieve(int N) {
  vector<bool> is_prime(N + 1, true);
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      primes.emplace_back(i);
    }
  }
  return primes;
}

void test_case() {
  int n;
  cin >> n;
  vector<int> primes = sieve(n);
  set<array<int, 3>> unq;
  for (int i = 0; i < (int) primes.size(); ++i) {
    int p1 = primes[i];
    for (int j = i; j < (int) primes.size(); ++j) {
      int p2 = primes[j];
      long long p3 = 1LL * p1 * p2 - p1 - p2;
      if (p3 > primes.back()) {
        break;
      }
      if (binary_search(primes.begin(), primes.end(), p3)) {
        vector<int> p = {p1, p2, p3};
        sort(p.begin(), p.end());
        unq.insert({p[0], p[1], p[2]});
      }
    }
  }
  long long res = 0;
  for (auto i : unq) {
    if (i[0] == i[1] && i[1] == i[2]) {
      res += 1;
    } else if (i[0] == i[1]) {
      res += 3;
    } else if (i[1] == i[2]) {
      res += 3;
    } else if (i[2] == i[0]) {
      res += 3;
    } else {
      res += 6;
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
