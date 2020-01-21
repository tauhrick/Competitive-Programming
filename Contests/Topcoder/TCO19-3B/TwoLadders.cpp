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

class TwoLadders {
public:
  long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y) {
    int n = X.size();
    int mx_lvl = *max_element(Y.begin(), Y.end());
    map<pair<int, pair<int, int>>, long long> dp;
    function<long long(int, int, int)> solve = [&](int lvl, int left, int right) {
      pair<int, pair<int, int>> arg = {lvl, {left, right}};
      if (!dp.count(arg)) {
        long long ans = LLONG_MAX;
        int pos;
        if (lvl == 0) {
          pos = sx;
        } else {
          pos = (left ? lx1 : lx2);
        }
        long long mn = LLONG_MAX, mx = LLONG_MIN;
        int nxt_lvl = INT_MAX;
        for (int i = 0; i < n; ++i) {
          if (Y[i] == lvl) {
            mn = min(mn, 1LL * X[i]);
            mx = max(mx, 1LL * X[i]);
          }
          if (Y[i] > lvl) {
            nxt_lvl = min(nxt_lvl, Y[i]);
          }
        }
        if (mn == LLONG_MAX && mx == LLONG_MIN) {
          { // Go l
            ans = min(ans, nxt_lvl - lvl + abs(pos - lx1) + solve(nxt_lvl, 1, 0));
          }
          { // Go r
            ans = min(ans, nxt_lvl - lvl + abs(pos - lx2) + solve(nxt_lvl, 0, 1));
          }
        } else {
          { // Go left
            long long tot = LLONG_MAX;
            { // l r
              long long steps = 0;
              if (mx <= pos) {
                steps += abs(mn - pos);
                if (lvl < mx_lvl) {
                  steps += abs(lx1 - mn);
                }
              } else {
                steps += 2 * max(0LL, pos - mn);
                steps += (mx - pos);
                if (lvl < mx_lvl) {
                  steps += abs(mx - lx1);
                }
              }
              tot = min(tot, steps);
            }
            { // r l
              long long steps = 0;
              if (mn >= pos) {
                steps += abs(mx - pos);
                if (lvl < mx_lvl) {
                  steps += abs(lx1 - mx);
                }
              } else {
                steps += 2 * max(0LL, mx - pos);
                steps += (pos - mn);
                if (lvl < mx_lvl) {
                  steps += abs(mn - lx1);
                }
              }
              tot = min(tot, steps);
            }
            long long curr = tot;
            if (lvl < mx_lvl) {
              curr += nxt_lvl - lvl + solve(nxt_lvl, 1, 0);
            }
            ans = min(ans, curr);
          }
          { // Go right
            long long tot = LLONG_MAX;
            { // l r
              long long steps = 0;
              if (mx <= pos) {
                steps += abs(mn - pos);
                if (lvl < mx_lvl) {
                  steps += abs(lx2 - mn);
                }
              } else {
                steps += 2 * max(0LL, pos - mn);
                steps += (mx - pos);
                if (lvl < mx_lvl) {
                  steps += abs(mx - lx2);
                }
              }
              tot = min(tot, steps);
            }
            { // r l
              long long steps = 0;
              if (mn >= pos) {
                steps += abs(mx - pos);
                if (lvl < mx_lvl) {
                  steps += abs(lx2 - mx);
                }
              } else {
                steps += 2 * max(0LL, mx - pos);
                steps += (pos - mn);
                if (lvl < mx_lvl) {
                  steps += abs(mn - lx2);
                }
              }
              tot = min(tot, steps);
            }
            long long curr = tot;
            if (lvl < mx_lvl) {
              curr += nxt_lvl - lvl + solve(nxt_lvl, 0, 1);
            }
            ans = min(ans, curr);
          }
        }
        dp[arg] = ans;
      }
      return dp[arg];
    };
    return solve(0, 0, 0);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int sx                    = 10;
			int lx1                   = 0;
			int lx2                   = 100;
			int X[]                   = {47, 42};
			int Y[]                   = {0, 0};
			long long expected__      = 37;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sx                    = 10;
			int lx1                   = 8;
			int lx2                   = 11;
			int X[]                   = {10, 12};
			int Y[]                   = {1, 1};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sx                    = 10;
			int lx1                   = 8;
			int lx2                   = 42;
			int X[]                   = {10, 12};
			int Y[]                   = {1, 1};
			long long expected__      = 7;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sx                    = 10;
			int lx1                   = 8;
			int lx2                   = 42;
			int X[]                   = {10, 100, 12};
			int Y[]                   = {1, 0, 1};
			long long expected__      = 181;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sx                    = 500000000;
			int lx1                   = 1;
			int lx2                   = 999999999;
			int X[]                   = {0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000};
			int Y[]                   = {1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 999999947, 999999947, 900000047, 900000047};
			long long expected__      = 8499999959LL;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sx                    = ;
			int lx1                   = ;
			int lx2                   = ;
			int X[]                   = ;
			int Y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sx                    = ;
			int lx1                   = ;
			int lx2                   = ;
			int X[]                   = ;
			int Y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sx                    = ;
			int lx1                   = ;
			int lx2                   = ;
			int X[]                   = ;
			int Y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TwoLadders().minSteps(sx, lx1, lx2, vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
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
