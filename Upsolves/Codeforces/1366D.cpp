#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kN = int(1e7) + 1;

vector<int> min_fact;

void Pre() {
  min_fact.resize(kN, INT_MAX);
  for (int i = 2; i < kN; ++i) {
    if (min_fact[i] == INT_MAX) {
      for (int j = i; j < kN; j += i) {
        min_fact[j] = min(min_fact[j], i);
      }
    }
  }
}

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<int> a;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<int> d1(n, -1), d2(n, -1);
    for (int i = 0; i < n; ++i) {
      int buff = a[i];
      vector<int> facts;
      while (a[i] != 1) {
        facts.emplace_back(min_fact[a[i]]);
        a[i] /= min_fact[a[i]];
      }
      facts.resize(unique(facts.begin(), facts.end()) - facts.begin());
      int sz = 1 << int(facts.size());
      for (int mask = 0; mask < sz; ++mask) {
        int f1 = 1;
        int f2 = 1;
        for (int j = 0; j < int(facts.size()); ++j) {
          if ((mask >> j) & 1) {
            f1 *= facts[j];
          } else {
            f2 *= facts[j];
          }
        }
        if (min(f1, f2) != 1 && gcd(buff, f1 + f2) == 1) {
          d1[i] = f1, d2[i] = f2;
          break;
        }
      }
    }
    for (auto &i : d1) {
      cout << i << " ";
    }
    cout << "\n";
    for (auto &i : d2) {
      cout << i << " ";
    }
    cout << "\n";
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Pre();
  Task t;
  t.Perform();
  return 0;
}