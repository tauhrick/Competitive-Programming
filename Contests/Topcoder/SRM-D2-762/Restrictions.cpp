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

class Restrictions {
public:
  vector <int> exist(int n, int m, vector <int> type, vector <int> l, vector <int> r, vector <int> val) {
    vector<pair<int, int>> lim(n, make_pair(1, 1e6));
    for (int i = 0; i < m; ++i) {
      for (int j = l[i]; j <= r[i]; ++j) {
        if (type[i] == 1) {
          lim[j].first = max(lim[j].first, val[i]);
        } else if (type[i] == 2) {
          lim[j].second = min(lim[j].second, val[i]);
        } else {
          assert(false);
        }
      }
    }
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      if (lim[i].first > lim[i].second) {
        return vector<int>{-1};
      } else {
        res[i] = lim[i].first;
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
			int n                     = 6;
			int m                     = 5;
			int type[]                = {1,1,2,2,2};
			int l[]                   = {0,1,2,1,2};
			int r[]                   = {5,3,3,4,2};
			int val[]                 = {10,18,25,26,16};
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Restrictions().exist(n, m, vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), vector <int>(val, val + (sizeof val / sizeof val[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int m                     = 3;
			int type[]                = {1,2,2};
			int l[]                   = {0,1,0};
			int r[]                   = {1,1,0};
			int val[]                 = {3,4,4};
			int expected__[]          = {3, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Restrictions().exist(n, m, vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), vector <int>(val, val + (sizeof val / sizeof val[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 2: {
			int n                     = ;
			int m                     = ;
			int type[]                = ;
			int l[]                   = ;
			int r[]                   = ;
			int val[]                 = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = Restrictions().exist(n, m, vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), vector <int>(val, val + (sizeof val / sizeof val[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 3: {
			int n                     = ;
			int m                     = ;
			int type[]                = ;
			int l[]                   = ;
			int r[]                   = ;
			int val[]                 = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = Restrictions().exist(n, m, vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), vector <int>(val, val + (sizeof val / sizeof val[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int n                     = ;
			int m                     = ;
			int type[]                = ;
			int l[]                   = ;
			int r[]                   = ;
			int val[]                 = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = Restrictions().exist(n, m, vector <int>(type, type + (sizeof type / sizeof type[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])), vector <int>(val, val + (sizeof val / sizeof val[0])));
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
