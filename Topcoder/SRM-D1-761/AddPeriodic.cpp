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

class AddPeriodic {
public:
  string add(string A, string B) {
    auto a = get_frac(A);
    auto b = get_frac(B);
    long long lcm = (a.second * b.second) / __gcd(a.second, b.second);
    pair<long long, long long> sum(a.first * (lcm / a.second) + b.first * (lcm / b.second), lcm);
    long long g = __gcd(sum.first, sum.second);
    sum.first /= g;
    sum.second /= g;
    string res = to_string(sum.first / sum.second);
    res += ".";
    long long rem = sum.first % sum.second;
    map<long long, int> info;
    int ctr = res.size();
    while (rem != 0) {
      rem *= 10;
      if (info.count(rem)) {
        res.insert(res.begin() + info[rem], '(');
        bool all_nine = true;
        for (int i = info[rem] + 1; i < (int) res.size(); ++i) {
          if (res[i] != '9') {
            all_nine = false;
          }
        }
        if (all_nine) {
          for (int i = info[rem] + 1; i < (int) res.size(); ++i) {
            res[i] = '0';
          }
        }
        res += ")";
        break;
      } else {
        int q = rem / sum.second;
        res += to_string(q);
        info[rem] = ctr++;
        rem %= sum.second;
      }
    }
    if (res.back() != ')') {
      res += "(0)";
    }
    return res;
  }
  
  pair<long long, long long> get_frac(string S) {
    pair<long long, long long> tot(1, 0);
    for (int i = 0; i < (int) S.size(); ++i) {
      if ('0' <= S[i] && S[i] <= '9') {
        tot.second *= 10;
        tot.second += S[i] - '0';
        tot.first *= 10;
      } else if (S[i] == '.') {
        tot.first = 1;
      }
    }
    pair<long long, long long> sub(1, 0);
    for (int i = 0; i < (int) S.size(); ++i) {
      if ('0' <= S[i] && S[i] <= '9') {
        sub.second *= 10;
        sub.second += S[i] - '0';
        sub.first *= 10;
      } else if (S[i] == '.') {
        sub.first = 1;
      } else if (S[i] == '(') {
        break;
      }
    }
    pair<long long, long long> ret(tot.second - sub.second, tot.first - sub.first);
    long long g = __gcd(ret.first, ret.second);
    ret.first /= g;
    ret.second /= g;
    return ret;
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
			string A                  = "0.33(333)";
			string B                  = "0.(66)";
			string expected__         = "1.(0)";

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A                  = "2.41(5)";
			string B                  = "5.36(22)";
			string expected__         = "7.(7)";

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A                  = "685.4(757)";
			string B                  = "45.356(43)";
			string expected__         = "730.832(210119)";

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string A                  = "0.(101)";
			string B                  = "0.(23)";
			string expected__         = "0.(333424)";

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string A                  = "0.0(999999)";
			string B                  = "1.5(00000)";
			string expected__         = "1.6(0)";

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AddPeriodic().add(A, B);
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
