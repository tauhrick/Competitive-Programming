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

template <uint32_t mod>
class Modular {
private:
  uint32_t n;

public:
  Modular(int64_t _n = 0) : n((_n >= 0 ? _n : mod - (-_n) % mod) % mod) {}

  uint32_t get() const {
    return n;
  }

  bool operator ==(const Modular& o) const {
    return n == o.n;
  }

  bool operator !=(const Modular& o) const {
    return n != o.n;
  }

  Modular& operator +=(const Modular& o) {
    n += o.n;
    n = (n < mod ? n : n - mod);
    return *this; 
  }

  Modular& operator -=(const Modular& o) {
    n += mod - o.n;
    n = (n < mod ? n : n - mod);
    return *this;
  }

  Modular& operator *=(const Modular& o) {
    n = uint64_t(n) * o.n % mod;
    return *this;
  }

  Modular& operator /=(const Modular& o) {
    return (*this) *= o.inv();
  }

  Modular operator +(const Modular& o) const {
    return Modular(*this) += o;
  }

  Modular operator -(const Modular& o) const {
    return Modular(*this) -= o;
  }

  Modular operator *(const Modular& o) const {
    return Modular(*this) *= o;
  }

  Modular operator /(const Modular& o) const {
    return Modular(*this) /= o;
  }

  Modular pow(uint64_t b) const {
    Modular ans(1), m = Modular(*this);
    while (b) {
      if (b & 1) {
        ans *= m;
      }
      m *= m;
      b >>= 1;
    }
    return ans;
  }

  Modular inv() const {
    int32_t a = n, b = mod, u = 0, v = 1;
    while (a) {
      int32_t t = b / a;
      b -= t * a;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    assert(b == 1);
    return Modular(u);
  }
};

using Mint = Modular<int(1e9 + 7)>;

class Strawberry {
public:
  int competitive(int n, int k, vector <int> A, vector <int> B) {
    int tot_ways = 2 * k + 1;
    vector<Mint> Pa(tot_ways);
    Mint tot_a(accumulate(A.begin(), A.end(), 0LL));
    for (int i = 0; i < tot_ways; ++i) {
      Pa[i] = Mint(A[i]) / tot_a;
    }
    vector<Mint> Pb(tot_ways);
    Mint tot_b(accumulate(B.begin(), B.end(), 0LL));
    for (int i = 0; i < tot_ways; ++i) {
      Pb[i] = Mint(B[i]) / tot_b;
    }
    vector<vector<Mint>> dp(110, vector<Mint>(220, Mint(0)));
    vector<vector<int>> seen(110, vector<int>(220, 0));
    function<Mint(int, int)> solve = [&](int round, int diff) {
      if (round == n + 1) {
        return Mint(1);
      }
      auto &ans = dp[round][diff + 110];
      auto &vis = seen[round][diff + 110];
      if (!vis) {
        vis = 1;
        for (int i = 0; i < tot_ways; ++i) {
          if (round & 1) {
            if (abs(diff + i) <= k) {
              ans += Pa[i] * solve(round + 1, diff + i);
            }
          } else {
            if (abs(diff - i) <= k) {
              ans += Pb[i] * solve(round + 1, diff - i);
            }
          }
        }
      }
      return ans;
    };
    int ans = solve(1, 0).get();
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
			int n                     = 1;
			int k                     = 3;
			int A[]                   = {1,1,1,1,1,1,1};
			int B[]                   = {1,1,1,1,1,1,1};
			int expected__            = 571428576;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 6;
			int k                     = 3;
			int A[]                   = {4,7,0,0,0,0,0};
			int B[]                   = {4,2,0,0,0,0,0};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int k                     = 3;
			int A[]                   = {4,7,0,0,0,0,0};
			int B[]                   = {4,2,0,0,0,0,0};
			int expected__            = 969874055;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 50;
			int k                     = 5;
			int A[]                   = {100,101,102,103,104,105,106,107,108,109,110};
			int B[]                   = {200,101,202,203,204,205,206,207,208,209,210};
			int expected__            = 440607283;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int k                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int k                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int k                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
