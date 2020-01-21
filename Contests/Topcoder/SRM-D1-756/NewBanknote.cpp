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

class NewBanknote {
public:
  vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay) {
    vector<int> notes;
    for (int i = 1; i <= 10000; i *= 10) {
      notes.emplace_back(i);
      notes.emplace_back(2 * i);
      notes.emplace_back(5 * i);
    }
    reverse(notes.begin(), notes.end());
    auto solve = [&](int left) {
      int cnt = 0;
      for (int i = 0; i < (int) notes.size(); ++i) {
        cnt += left / notes[i];
        left %= notes[i];
      }
      return cnt;
    };
    int q = amountsToPay.size();
    vector<int> ans(q, INT_MAX);
    for (int i = 0; i < q; ++i) {
      int prv = solve(amountsToPay[i]);
      for (int ex = 1; ex <= prv; ++ex) {
        int left = amountsToPay[i] - ex * newBanknote;
        if (left < 0) {
          break;
        } else {
          ans[i] = min(ans[i], ex + solve(left));
        }
      }
      ans[i] = min(ans[i], prv);
    }
    return ans;
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
			int newBanknote           = 4700;
			int amountsToPay[]        = {53, 9400, 9401, 30000};
			int expected__[]          = {3, 2, 3, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NewBanknote().fewestPieces(newBanknote, vector <int>(amountsToPay, amountsToPay + (sizeof amountsToPay / sizeof amountsToPay[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int newBanknote           = 1234;
			int amountsToPay[]        = {1233, 1234, 1235};
			int expected__[]          = {6, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NewBanknote().fewestPieces(newBanknote, vector <int>(amountsToPay, amountsToPay + (sizeof amountsToPay / sizeof amountsToPay[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int newBanknote           = 1000;
			int amountsToPay[]        = {1233, 100047};
			int expected__[]          = {6, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NewBanknote().fewestPieces(newBanknote, vector <int>(amountsToPay, amountsToPay + (sizeof amountsToPay / sizeof amountsToPay[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int newBanknote           = ;
			int amountsToPay[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NewBanknote().fewestPieces(newBanknote, vector <int>(amountsToPay, amountsToPay + (sizeof amountsToPay / sizeof amountsToPay[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int newBanknote           = ;
			int amountsToPay[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NewBanknote().fewestPieces(newBanknote, vector <int>(amountsToPay, amountsToPay + (sizeof amountsToPay / sizeof amountsToPay[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int newBanknote           = ;
			int amountsToPay[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NewBanknote().fewestPieces(newBanknote, vector <int>(amountsToPay, amountsToPay + (sizeof amountsToPay / sizeof amountsToPay[0])));
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
