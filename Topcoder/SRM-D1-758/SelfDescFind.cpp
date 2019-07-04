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

class SelfDescFind {
public:
  string construct(vector <int> digits) {
    int d = digits.size();
    vector<int> a(d);
    string res;
    function<void(int, int)> solve = [&](int ind, int prv) {
      if (ind == d) {
        if (prv == 2 * d) {
          vector<int> cnt(10);
          for (auto dig : digits) {
            ++cnt[dig];
          }
          for (auto dig : a) {
            ++cnt[dig];
          }
          vector<pair<int, int>> t;
          for (int i = 0; i < d; ++i) {
            if (a[i] != cnt[digits[i]]) {
              return;
            } else {
              t.emplace_back(a[i], digits[i]);
            }
          }
          sort(t.begin(), t.end());
          string curr;
          for (auto p : t) {
            curr += '0' + p.first;
            curr += '0' + p.second;
          }
          if (res.size() == 0) {
            res = curr;
          } else {
            res = min(res, curr);
          }
        }
      } else {
        for (int curr = 0; curr <= 9; ++curr) {
          if (prv + curr <= 2 * d && prv + curr + (d - ind - 1) * 9 >= 2 * d) {
            a[ind] = curr;
            solve(ind + 1, prv + curr);            
          }
        }
      }
    };
    solve(0, 0);
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int digits[]              = {1};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int digits[]              = {2};
			string expected__         = "22";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int digits[]              = {0,1,3,4};
			string expected__         = "10143133";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int digits[]              = {0,1,2,4,5,6,8,9};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int digits[]              = {0,1,2,3,5,6,8,9};
			string expected__         = "1016181923253251";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int digits[]              = {4};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int digits[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int digits[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int digits[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
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
