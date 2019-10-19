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

class ReallyMagicSquare {
public:
  vector <int> reconstruct(vector <int> topRow, vector <int> mainDiagonal) {
    if (topRow.front() != mainDiagonal.front()) {
      return vector<int>{};
    }
    int n = topRow.size();
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    for (int c = 0; c < n; ++c) {
      grid[1][c + 1] = topRow[c];
    }
    for (int i = 0; i < n; ++i) {
      grid[i + 1][i + 1] = mainDiagonal[i];
    }
    for (int r = 2; r <= n; ++r) {
      for (int c = r + 1; c <= n; ++c) {
        grid[r][c] = grid[r - 1][c] + grid[r][c - 1] - grid[r - 1][c - 1];
      }
    }
    for (int _r = 2; _r <= n; ++_r) {
      int r = _r;
      int c = 1;
      while (r <= n) {
        grid[r][c] = grid[r][c + 1] + grid[r - 1][c] - grid[r - 1][c + 1];
        ++r, ++c;
      }
    }
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        res.emplace_back(grid[i][j]);
      }
    }
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
			int topRow[]              = {140, 80, 160, 60};
			int mainDiagonal[]        = {140, 30, 120, 50};
			int expected__[]          = {140, 80, 160, 60, 90, 30, 110, 10, 100, 40, 120, 20, 130, 70, 150, 50 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ReallyMagicSquare().reconstruct(vector <int>(topRow, topRow + (sizeof topRow / sizeof topRow[0])), vector <int>(mainDiagonal, mainDiagonal + (sizeof mainDiagonal / sizeof mainDiagonal[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int topRow[]              = {1,7};
			int mainDiagonal[]        = {1,4};
			int expected__[]          = {1, 7, -2, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ReallyMagicSquare().reconstruct(vector <int>(topRow, topRow + (sizeof topRow / sizeof topRow[0])), vector <int>(mainDiagonal, mainDiagonal + (sizeof mainDiagonal / sizeof mainDiagonal[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int topRow[]              = {47,47,47,47,47};
			int mainDiagonal[]        = {47,47,47,47,47};
			int expected__[]          = {47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ReallyMagicSquare().reconstruct(vector <int>(topRow, topRow + (sizeof topRow / sizeof topRow[0])), vector <int>(mainDiagonal, mainDiagonal + (sizeof mainDiagonal / sizeof mainDiagonal[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int topRow[]              = ;
			int mainDiagonal[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ReallyMagicSquare().reconstruct(vector <int>(topRow, topRow + (sizeof topRow / sizeof topRow[0])), vector <int>(mainDiagonal, mainDiagonal + (sizeof mainDiagonal / sizeof mainDiagonal[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int topRow[]              = ;
			int mainDiagonal[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ReallyMagicSquare().reconstruct(vector <int>(topRow, topRow + (sizeof topRow / sizeof topRow[0])), vector <int>(mainDiagonal, mainDiagonal + (sizeof mainDiagonal / sizeof mainDiagonal[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int topRow[]              = ;
			int mainDiagonal[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ReallyMagicSquare().reconstruct(vector <int>(topRow, topRow + (sizeof topRow / sizeof topRow[0])), vector <int>(mainDiagonal, mainDiagonal + (sizeof mainDiagonal / sizeof mainDiagonal[0])));
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
