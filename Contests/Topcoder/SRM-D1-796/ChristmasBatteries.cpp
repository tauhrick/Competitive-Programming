#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class ChristmasBatteries {
 private:
  int b, n, x, y, z, m;
  vector<vector<int>> dp;

 public:
  int mostFun(int B, int N, int X, int Y, int Z, int M) {
    b = B, n = N, x = X, y = Y, z = Z, m = M;
    dp = vector<vector<int>>(n + 1, vector<int>(b + 1, -1));
    for (int ind = n; ind >= 0; --ind) {
      for (int taken = b; taken >= 0; --taken) {
        auto &ans = dp[ind][taken];
        if (ind == n) {
          ans = 0;
        } else {
          ans = dp[ind + 1][taken];
          int cost = ind % 5;
          if (cost + taken <= b) {
            int fun = (1LL * x * ind * ind + 1LL * y * ind + z) % m;
            ans = max(ans, fun + dp[ind + 1][cost + taken]);
          }
        }
      }
    }
    return dp[0][0];
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
      int B                     = 0;
      int N                     = 5;
      int X                     = 1;
      int Y                     = 1;
      int Z                     = 1;
      int M                     = 1000;
      int expected__            = 1;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 1: {
      int B                     = 3;
      int N                     = 5;
      int X                     = 1;
      int Y                     = 1;
      int Z                     = 1;
      int M                     = 1000;
      int expected__            = 14;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 2: {
      int B                     = 3;
      int N                     = 5;
      int X                     = 1;
      int Y                     = 1;
      int Z                     = 1;
      int M                     = 13;
      int expected__            = 11;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 3: {
      int B                     = 4;
      int N                     = 10000;
      int X                     = 123;
      int Y                     = 456;
      int Z                     = 789;
      int M                     = 1;
      int expected__            = 0;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 4: {
      int B                     = 7;
      int N                     = 4;
      int X                     = 3;
      int Y                     = 5;
      int Z                     = 7;
      int M                     = 997;
      int expected__            = 100;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
    case 5: {
      int B                     = 2;
      int N                     = 12345;
      int X                     = 234;
      int Y                     = 34;
      int Z                     = 5;
      int M                     = 117;
      int expected__            = 143371;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }

    // custom cases

      case 6: {
      int B                     = 5;
      int N                     = 939800;
      int X                     = 95;
      int Y                     = 760;
      int Z                     = 117;
      int M                     = 475;
      int expected__            = 21991839;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }
/*      case 7: {
      int B                     = ;
      int N                     = ;
      int X                     = ;
      int Y                     = ;
      int Z                     = ;
      int M                     = ;
      int expected__            = ;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
      return verify_case(casenum__, expected__, received__, clock()-start__);
    }*/
/*      case 8: {
      int B                     = ;
      int N                     = ;
      int X                     = ;
      int Y                     = ;
      int Z                     = ;
      int M                     = ;
      int expected__            = ;

      std::clock_t start__      = std::clock();
      int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
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
