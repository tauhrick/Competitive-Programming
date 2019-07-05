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

class MoreSquares {
public:
  int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix) {
    vector<pair<int, int>> pts(N);
    int l = Xprefix.size();
    for (int i = 0; i < l; ++i) {
      pts[i] = {Xprefix[i], Yprefix[i]};
    }
    for (int i = l; i < N; ++i) {
      pts[i].first = (pts[i - 1].first * 47 + 42) % SX;
      pts[i].second = (pts[i - 1].second * 47 + 42) % SY;
    }
    sort(pts.begin(), pts.end());
    pts.resize(distance(pts.begin(), unique(pts.begin(), pts.end())));
    set<pair<int, int>> add;
    auto get_point = [&](int p, int ii, int jj, int sgn) {
      return make_pair(pts[p].first - 1 * sgn * (pts[jj].second - pts[ii].second), pts[p].second + 1 * sgn * (pts[jj].first - pts[ii].first));
    };
    for (int i = 0; i < (int) pts.size(); ++i) {
      for (int j = i + 1; j < (int) pts.size(); ++j) {
        for (auto sgn : {1, -1}) {
          auto p1 = get_point(i, i, j, sgn);
          auto p2 = get_point(j, i, j, sgn);
          auto f1 = binary_search(pts.begin(), pts.end(), p1);
          auto f2 = binary_search(pts.begin(), pts.end(), p2);
          if (f1 && !f2) {
            add.insert(p2);
          } else if (f2 && !f1) {
            add.insert(p1);
          }
        }
      }
    }
    return (int) add.size();
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
			int N                     = 3;
			int SX                    = 100;
			int SY                    = 100;
			int Xprefix[]             = {3, 0, 2};
			int Yprefix[]             = {0, 1, 2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = MoreSquares().countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix + (sizeof Xprefix / sizeof Xprefix[0])), vector <int>(Yprefix, Yprefix + (sizeof Yprefix / sizeof Yprefix[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int SX                    = 100;
			int SY                    = 100;
			int Xprefix[]             = {47, 47, 47, 47, 47};
			int Yprefix[]             = {47, 47, 47, 47, 47};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = MoreSquares().countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix + (sizeof Xprefix / sizeof Xprefix[0])), vector <int>(Yprefix, Yprefix + (sizeof Yprefix / sizeof Yprefix[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 23;
			int SX                    = 11;
			int SY                    = 13;
			int Xprefix[]             = {7};
			int Yprefix[]             = {0};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = MoreSquares().countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix + (sizeof Xprefix / sizeof Xprefix[0])), vector <int>(Yprefix, Yprefix + (sizeof Yprefix / sizeof Yprefix[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int SX                    = ;
			int SY                    = ;
			int Xprefix[]             = ;
			int Yprefix[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MoreSquares().countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix + (sizeof Xprefix / sizeof Xprefix[0])), vector <int>(Yprefix, Yprefix + (sizeof Yprefix / sizeof Yprefix[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			int SX                    = ;
			int SY                    = ;
			int Xprefix[]             = ;
			int Yprefix[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MoreSquares().countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix + (sizeof Xprefix / sizeof Xprefix[0])), vector <int>(Yprefix, Yprefix + (sizeof Yprefix / sizeof Yprefix[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int SX                    = ;
			int SY                    = ;
			int Xprefix[]             = ;
			int Yprefix[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MoreSquares().countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix + (sizeof Xprefix / sizeof Xprefix[0])), vector <int>(Yprefix, Yprefix + (sizeof Yprefix / sizeof Yprefix[0])));
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
