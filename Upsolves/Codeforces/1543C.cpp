#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

namespace floating_comparisons {

const double kEps = 1.0e-6;

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= kEps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > kEps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + kEps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + kEps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + kEps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + kEps > b ) return true;else return false;}

} // namespace floating_comparison

const int kM = 20;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  double c, m, p, v; 

  void Read() {
    cin >> c >> m >> p >> v;
  }
 
  void Solve() {
    cout << fixed << setprecision(10) << Brute(c, m, p) << '\n';
  }

  double Brute(double cc, double mm, double pp) {
    bool cc_zero = floating_comparisons::equalTo(cc, 0);
    bool mm_zero = floating_comparisons::equalTo(mm, 0);
    double res = pp;
    if (!cc_zero) {
      double ded = min(cc, v);
      if (!mm_zero) {
        res += cc * (1 + Brute(cc - ded, mm + ded / 2, pp + ded / 2));
      } else {
        res += cc * (1 + Brute(cc - ded, mm, pp + ded));
      }
    }
    if (!mm_zero) {
      double ded = min(mm, v);
      if (!cc_zero) {
        res += mm * (1 + Brute(cc + ded / 2, mm - ded, pp + ded / 2));
      } else {
        res += mm * (1 + Brute(cc, mm - ded, pp + ded));
      }
    }
    return res;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}