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

class ReconstructNumber {
public:
  string smallest(string comparisons) {
    int n = comparisons.size();
    vector<vector<int>> dp(n, vector<int>(10)), seen(n, vector<int>(10));
    vector<vector<int>> nxt(n, vector<int>(10, -1));
    function<int(int, int)> solve = [&](int ind, int prv) {
      if (ind == n) {
        return 1;
      }
      auto& ans = dp[ind][prv];
      auto& vis = seen[ind][prv];
      if (!vis) {
        vis = true;
        ans = false;
        for (int curr = 0; curr <= 9; ++curr) {
          if (comparisons[ind] == '<' && prv < curr && solve(ind + 1, curr))  {
            ans = true;
            nxt[ind][prv] = curr;
            break;
          } else if (comparisons[ind] == '>' && prv > curr && solve(ind + 1, curr)) {
            ans = true;
            nxt[ind][prv] = curr;
            break;
          } else if (comparisons[ind] == '=' && prv == curr && solve(ind + 1, curr)) {
            ans = true;
            nxt[ind][prv] = curr;
            break;
          } else if (comparisons[ind] == '!' && prv != curr && solve(ind + 1, curr)) {
            ans = true;
            nxt[ind][prv] = curr;
            break;
          }
        }
      }
      return ans;
    };
    for (int dig = 1; dig <= 9; ++dig) {
      if (solve(0, dig)) {
        string res = to_string(dig);
        int ind = 0, prv = dig;
        while (ind != n) {
          res += to_string(nxt[ind][prv]);
          prv = nxt[ind++][prv];
        }
        return res;
      }
    }
    return string{};
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
			string comparisons        = ">=!<";
			string expected__         = "10012";

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string comparisons        = "====!====";
			string expected__         = "1111100000";

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string comparisons        = "";
			string expected__         = "1";

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string comparisons        = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string comparisons        = "><<>><=<=>=>";
			string expected__         = "1012101122110";

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string comparisons        = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string comparisons        = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string comparisons        = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ReconstructNumber().smallest(comparisons);
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
