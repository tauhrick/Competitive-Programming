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

class FixedPointReversals {
public:
  vector <int> sort(vector <int> A, int fixed) {
    map<int, int> cnt;
    for (auto i : A) {
      ++cnt[i];
    }
    vector<int> B;
    for (auto p : cnt) {
      for (int i = 0; i < p.second; ++i) {
        B.emplace_back(p.first);
      }
    }
    if (B[fixed] != A[fixed]) {
      return vector<int>{-1};
    }
    vector<int> res;
    auto add = [&](int st, int en) {
      res.emplace_back(st);
      res.emplace_back(en + 1);
      reverse(A.begin() + st, A.begin() + en + 1);
    };
    for (int i = A.size() - 1; i >= 0; --i) {
      if (A[i] == B[i]) {
        continue;
      }
      int ind = i - 1;
      while (ind == fixed || (ind >= 0 && A[ind] != B[i])) {
        --ind;
      }
      assert(ind >= 0);
      if ((i > fixed && ind > fixed) || (i < fixed && ind < fixed)) {
        add(ind, i);
      } else { // i > fixed && ind < fixed
        int r = i - fixed;
        int l = fixed - ind;
        if (l > r) {
          int mirror = fixed - (i - fixed);
          add(ind, mirror);
          add(mirror, i);
        } else if (r > l) {
          int mirror = fixed + (fixed - ind);
          add(ind, mirror);
          add(mirror, i);
        } else {
          add(ind, i);
        }
      }
    }
    assert(A == B);
    return res;
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int A[]                   = {10, 20, 30, 40, 50};
			int fixed                 = 2;
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {10, 20, 40, 30, 50};
			int fixed                 = 2;
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {20, 10, 10, 10, 10, 10};
			int fixed                 = 4;
			int expected__[]          = {0, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1, 50, 40, 30, 20, 10};
			int fixed                 = 0;
			int expected__[]          = {1, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {20, 10, 30, 50, 40};
			int fixed                 = 2;
			int expected__[]          = {0, 2, 3, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int A[]                   = {10, 20, 30, 40, 50};
			int fixed                 = 2;
			int expected__[]          = {};

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
      case 6: {
			int A[]                   = {20, 10, 10, 10, 10, 10};
			int fixed                 = 4;
			int expected__[]          = {0, 6};

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
/*      case 7: {
			int A[]                   = ;
			int fixed                 = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FixedPointReversals().sort(vector <int>(A, A + (sizeof A / sizeof A[0])), fixed);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
