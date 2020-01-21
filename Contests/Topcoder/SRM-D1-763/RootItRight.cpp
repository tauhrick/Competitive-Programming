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

class RootItRight {
public:
  long long findMinimumTotalCost(int N, vector <int> edge, vector <int> val, int D, int seed, int MX) {
    vector<int> A(2 * N);
    A[0] = seed;
    for (int i = 1; i <= 2 * N - 1; ++i) {
      A[i] = (A[i - 1] * 1103515245LL + 12345) % 2147483648LL;
    }
    auto E = edge;
    for (int i = edge.size(); i <= N - 1; ++i) {
      int nxt = (A[i] % min(i, D)) + i - min(i, D);
      E.emplace_back(nxt);
    }
    vector<vector<int>> G(N);
    for (int i = 1; i <= N - 1; ++i) {
      G[i].emplace_back(E[i]);
      G[E[i]].emplace_back(i);
    }
    auto V = val;
    for (int i = val.size(); i <= N - 1; ++i) {
      int nxt = A[N + i] % MX;
      V.emplace_back(nxt);
    }
    vector<int> dep(N), sz(N);
    vector<long long> dp(N);
    function<void(int, int, int)> dfs_pre = [&](int u, int p, int d) {
      sz[u] = 1;
      dep[u] = d;
      for (auto v : G[u]) {
        if (v != p) {
          dfs_pre(v, u, d + 1);
          sz[u] += sz[v];
          dp[u] += dp[v];
        }
      }
      dp[u] += sz[u] * V[u];
    };
    dfs_pre(0, 0, 0);
    long long ans = 0;
    for (int i = 0; i <= N - 1; ++i) {
      ans += 1LL * sz[i] * dep[i] * V[i];
    }
    function<void(int, int, long long, long long)> dfs = [&](int u, int p, long long curr, long long inc) {
      ans = min(ans, curr);
      long long tot = 0;
      for (auto v : G[u]) {
        if (v != p) {
          tot += dp[v];
        }
      }
      for (auto v : G[u]) {
        if (v != p) {
          long long add = tot - dp[v];
          add += 1LL * (N - sz[v]) * V[u];
          dfs(v, u, curr + inc + add - dp[v], inc + add);
        }
      }
    };
    dfs(0, 0, ans, 0);
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
			int N                     = 4;
			int edge[]                = {-1,0,1,2};
			int val[]                 = {4,3,3,4};
			int D                     = 1;
			int seed                  = 0;
			int MX                    = 5;
			long long expected__      = 18;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			int edge[]                = {-1,0,0,0};
			int val[]                 = {3,2,3,0};
			int D                     = 1;
			int seed                  = 0;
			int MX                    = 4;
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 5;
			int edge[]                = {-1,0,0,1,3};
			int val[]                 = {5,0,3,2,3};
			int D                     = 1;
			int seed                  = 0;
			int MX                    = 6;
			long long expected__      = 20;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 17;
			int edge[]                = {-1};
			int val[]                 = {};
			int D                     = 7;
			int seed                  = 176;
			int MX                    = 15;
			long long expected__      = 620;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 200000;
			int edge[]                = {-1,0,0,0};
			int val[]                 = {4,7};
			int D                     = 1;
			int seed                  = 0;
			int MX                    = 1000;
			long long expected__      = 166346919874650680LL;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int edge[]                = ;
			int val[]                 = ;
			int D                     = ;
			int seed                  = ;
			int MX                    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int edge[]                = ;
			int val[]                 = ;
			int D                     = ;
			int seed                  = ;
			int MX                    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int edge[]                = ;
			int val[]                 = ;
			int D                     = ;
			int seed                  = ;
			int MX                    = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = RootItRight().findMinimumTotalCost(N, vector <int>(edge, edge + (sizeof edge / sizeof edge[0])), vector <int>(val, val + (sizeof val / sizeof val[0])), D, seed, MX);
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
