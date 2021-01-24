#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

template <uint32_t mod>
class Modular {
 public:
  Modular(int64_t _n = 0) : n(uint32_t((_n >= 0 ? _n : mod - (-_n) % mod) % mod)) {}

  uint32_t get() const { return n; }
  bool operator==(const Modular &o) const { return n == o.n; }
  bool operator!=(const Modular &o) const { return n != o.n; }
  Modular& operator/=(const Modular &o) { return (*this) *= o.inv(); }
  Modular operator+(const Modular &o) const { return Modular(*this) += o; }
  Modular operator-(const Modular &o) const { return Modular(*this) -= o; }
  Modular operator*(const Modular &o) const { return Modular(*this) *= o; }
  Modular operator/(const Modular &o) const { return Modular(*this) /= o; }
  friend string to_string(const Modular &m) { return to_string(m.get()); }

  Modular& operator+=(const Modular &o) {
    n += o.n;
    n = (n < mod ? n : n - mod);
    return *this; 
  }

  Modular& operator-=(const Modular &o) {
    n += mod - o.n;
    n = (n < mod ? n : n - mod);
    return *this;
  }

  Modular& operator*=(const Modular &o) {
    n = uint32_t(uint64_t(n) * o.n % mod);
    return *this;
  }

  Modular pow(uint64_t b) const {
    Modular ans(1), m = Modular(*this);
    while (b) {
      if (b & 1) {
        ans *= m;
      }
      m *= m;
      b >>= 1;
    }
    return ans;
  }

  Modular inv() const {
    int32_t a = n, b = mod, u = 0, v = 1;
    while (a) {
      int32_t t = b / a;
      b -= t * a;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    assert(b == 1);
    return Modular(u);
  }

 private:
  uint32_t n;
};

class SuperSubset {
 public:
  int solve(vector <int> _A, int _Y) {
    a = _A;
    y = _Y;
    return Perform();  
  }

 private:
  using Mint = Modular<int(1e9) + 7>;

  int y;
  vector<int> a;

  int Perform() {
    int n = int(a.size());
    vector<vector<Mint>> dp(n, vector<Mint>(y + 1, Mint(0)));
    for (int ind = 0; ind < n; ++ind) {
      for (int left = 0; left <= y; ++left) {
        if (ind - 1 >= 0) {
          dp[ind][left] += Mint(2) * dp[ind - 1][left];
          if (left - a[ind] >= 0) {
            dp[ind][left] += dp[ind - 1][left - a[ind]];
          }
        } else {
          dp[ind][left] += Mint(2) * (left == 0);
          if (left - a[ind] == 0) {
            dp[ind][left] += Mint(1);
          }
        }
      }
    }
    return dp[n - 1][y].get();
  }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
  using std::string;
  using std::vector;
  int run_test_case(int);
  void run_test(int casenum = -1, bool quiet = false) {
    if (casenum != -1) {
      if (run_test_case(casenum) == -1 && !quiet) {
        std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
      }
      return;
    }
    
    int correct = 0, total = 0;
    for (int i=0;; ++i) {
      int x = run_test_case(i);
      if (x == -1) {
        if (i >= 100) break;
        continue;
      }
      correct += x;
      ++total;
    }
    
    if (total == 0) {
      std::cerr << "No test cases run." << std::endl;
    } else if (correct < total) {
      std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
    } else {
      std::cerr << "All " << total << " tests passed!" << std::endl;
    }
  }
  
  int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
    std::cerr << "Example " << casenum << "... "; 
    
    string verdict;
    vector<string> info;
    char buf[100];
    
    if (elapsed > CLOCKS_PER_SEC / 200) {
      std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
      info.push_back(buf);
    }
    
    if (expected == received) {
      verdict = "PASSED";
    } else {
      verdict = "FAILED";
    }
    
    std::cerr << verdict;
    if (!info.empty()) {
      std::cerr << " (";
      for (size_t i=0; i<info.size(); ++i) {
        if (i > 0) std::cerr << ", ";
        std::cerr << info[i];
      }
      std::cerr << ")";
    }
    std::cerr << std::endl;
    
    if (verdict == "FAILED") {
      std::cerr << "    Expected: " << expected << std::endl; 
      std::cerr << "    Received: " << received << std::endl; 
    }
    
    return verdict == "PASSED";
  }

  int run_test_case(int casenum__) {
    switch (casenum__) {
    case 0: {
      int A[]                   = {1, 2, 3};
      int Y                     = 3;
      int expected__            = 6;

      std::clock_t start__      = std::clock();
      int received__            = SuperSubset().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), Y);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
      int A[]                   = {1, 1, 1, 1, 1};
      int Y                     = 4;
      int expected__            = 10;

      std::clock_t start__      = std::clock();
      int received__            = SuperSubset().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), Y);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }

    // custom cases

/*      case 2: {
      int A[]                   = ;
      int Y                     = ;
      int expected__            = ;

      std::clock_t start__      = std::clock();
      int received__            = SuperSubset().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), Y);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }*/
/*      case 3: {
      int A[]                   = ;
      int Y                     = ;
      int expected__            = ;

      std::clock_t start__      = std::clock();
      int received__            = SuperSubset().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), Y);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }*/
/*      case 4: {
      int A[]                   = ;
      int Y                     = ;
      int expected__            = ;

      std::clock_t start__      = std::clock();
      int received__            = SuperSubset().solve(vector <int>(A, A + (sizeof A / sizeof A[0])), Y);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }*/
    default:
      return -1;
    }
  }
}

#include <cstdlib>
int main(int argc, char *argv[]) {
  if (argc == 1) {
    moj_harness::run_test();
  } else {
    for (int i=1; i<argc; ++i)
      moj_harness::run_test(std::atoi(argv[i]));
  }
}
// END CUT HERE
