#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kBits = 30;

class CapriciousSorting {
 public:
  int count(vector <int> _num) {
    num = _num;
    return Perform();
  }

 private:
  vector<int> num;
  vector<int> ways;
  vector<int> val;
  bool bad = false;

  int Perform() {
    ways.assign(kBits, -1);
    val.assign(kBits, -1);
    Solve(kBits - 1, num);
    int ans = !bad;
    for (auto &way : ways) {
      ans *= way;
    }
    return ans;
  }

  void Solve(int bit_pos, vector<int> &x) {
    if (bit_pos < 0) {
      if (int(x.size()) != 1) {
        bad = true;
      }
      return;
    }
    vector<int> bits(x.size());
    for (int i = 0; i < int(x.size()); ++i) {
      bits[i] = (x[i] >> bit_pos) & 1;
    }
    int cnt_01 = 0, cnt_10 = 0;
    for (int i = 1; i < int(bits.size()); ++i) {
      cnt_01 += bits[i - 1] == 0 && bits[i] == 1;
      cnt_10 += bits[i - 1] == 1 && bits[i] == 0;
    }
    if (cnt_01 > 0 && cnt_10 > 0) {
      ways[kBits] = 0;
      bad = true;
      return;
    } else if (cnt_01 == 0 && cnt_10 == 0) {
      if (val[bit_pos] == -1) {
        ways[bit_pos] = 2;
      }
      Solve(bit_pos - 1, x);
    } else {
      int new_val = (cnt_01 > 0 ? 0 : 1);
      if (val[bit_pos] != -1 && val[bit_pos] != new_val) {
        ways[bit_pos] = 0;
        bad = true;
        return;
      }
      ways[bit_pos] = 1;
      val[bit_pos] = new_val;
      vector<int> lc, rc;
      for (int i = 0; i < int(bits.size()); ++i) {
        if (bits[i] == new_val) {
          lc.push_back(x[i]);
        } else {
          rc.push_back(x[i]);
        }
      }
      Solve(bit_pos - 1, lc);
      Solve(bit_pos - 1, rc);
    }
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
			int num[]                 = {0, 1, 2, 3, 4, 5, 6, 7};
			int expected__            = 134217728;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int num[]                 = {7, 6, 5, 4, 3, 2, 1, 0};
			int expected__            = 134217728;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int num[]                 = {47, 47, 42};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int num[]                 = {84, 94, 68, 72, 96, 31, 2, 57};
			int expected__            = 67108864;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int num[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int num[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int num[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CapriciousSorting().count(vector <int>(num, num + (sizeof num / sizeof num[0])));
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
