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

class MaxCutFree {
public:
  int solve(int n, vector <int> a, vector <int> b) {
    vector<set<int>> G(n);
    for (int i = 0; i < (int) a.size(); ++i) {
      G[a[i]].insert(b[i]);
      G[b[i]].insert(a[i]);
    }
    auto get_cc = [&]() {
      int cc = 0;
      vector<bool> seen(n);
      function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        for (auto v : G[u]) {
          if (!seen[v]) {
            dfs(v);
          }
        }
      };
      for (int u = 0; u < n; ++u) {
        if (!seen[u]) {
          dfs(u);
          ++cc;
        }
      }
      return cc;
    };
    auto tot = get_cc();
    set<int> bad;
    vector<vector<int>> T(n);
    for (int i = 0; i < (int) a.size(); ++i) {
      G[a[i]].erase(b[i]);
      G[b[i]].erase(a[i]);
      auto curr = get_cc();
      if (curr > tot) {
        T[a[i]].emplace_back(b[i]);
        T[b[i]].emplace_back(a[i]);
        bad.insert(a[i]);
        bad.insert(b[i]);
      }
      G[a[i]].insert(b[i]);
      G[b[i]].insert(a[i]);
    }
    int res = n - bad.size();
    vector<bool> seen(n);
    vector<vector<int>> dp(n, vector<int>(2));
    function<void(int)> solve = [&](int u) {
      seen[u] = true;
      dp[u][true] = 1;
      for (auto v : T[u]) {
        if (!seen[v]) {
          solve(v);
          dp[u][true] += dp[v][false];
          dp[u][false] += max(dp[v][true], dp[v][false]);
        }
      }
    };
    for (auto u : bad) {
      if (!seen[u]) {
        solve(u);
        res += max(dp[u][true], dp[u][false]);
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
			int n                     = 4;
			int a[]                   = {0, 1, 2, 0};
			int b[]                   = {1, 2, 0, 3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 6;
			int a[]                   = {0,1,2,3,3};
			int b[]                   = {2,2,3,4,5};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int a[]                   = {0,2,4};
			int b[]                   = {1,3,5};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 4;
			int a[]                   = {0,0,0,1,1,2};
			int b[]                   = {1,2,3,2,3,3};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
