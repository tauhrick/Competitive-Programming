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

class LexicographicPartition {
public:
  vector <int> positiveSum(int n, vector <int> Aprefix, int seed, int Arange) {
    vector<int> A(n);
    for (int i = 0; i < (int) Aprefix.size(); ++i) {
      A[i] = Aprefix[i];
    }
    long long state = seed;
    for (int i = (int) Aprefix.size(); i < n; ++i) {
      state = (1103515245 * state + 12345);
      A[i] = state % (2 * Arange + 1);
      A[i] -= Arange;
      state = state % (1LL << 31);
    }
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    if (sum <= 0) {
      return vector<int>{-1};
    }
    vector<int> lens;
    long long curr_sum = 0;
    int len = 0;
    for (int i = 0; i < n; ++i) {
      curr_sum += A[i];
      sum -= A[i];
      ++len;
      if (curr_sum > 0 && sum > 0) {
        lens.emplace_back(len);
        len = curr_sum = 0;
      }
    }
    lens.emplace_back(len);
    reverse(lens.begin(), lens.end());
    lens.emplace_back(lens.size());
    reverse(lens.begin(), lens.end());
    while (lens.size() - 1 > 200) {
      lens.pop_back();
    }
    return lens;
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
			int n                     = 3;
			int Aprefix[]             = {3,-7,8};
			int seed                  = 1;
			int Arange                = 1;
			int expected__[]          = {2, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n                     = 5;
			int Aprefix[]             = {0,1,0,1,2};
			int seed                  = 42;
			int Arange                = 47;
			int expected__[]          = {3, 2, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int n                     = 5;
			int Aprefix[]             = {-1,2,-3,4,-5};
			int seed                  = 777;
			int Arange                = 4747;
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int n                     = 1;
			int Aprefix[]             = {0};
			int seed                  = 12;
			int Arange                = 34;
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int n                     = 10;
			int Aprefix[]             = {4,-7,4,-7};
			int seed                  = 123456789;
			int Arange                = 5447;
			int expected__[]          = {6, 1, 5, 1, 1, 1, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int Aprefix[]             = ;
			int seed                  = ;
			int Arange                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int Aprefix[]             = ;
			int seed                  = ;
			int Arange                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int Aprefix[]             = ;
			int seed                  = ;
			int Arange                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LexicographicPartition().positiveSum(n, vector <int>(Aprefix, Aprefix + (sizeof Aprefix / sizeof Aprefix[0])), seed, Arange);
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
