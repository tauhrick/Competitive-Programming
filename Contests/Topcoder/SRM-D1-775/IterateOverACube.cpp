#include <bits/stdc++.h>
using namespace std;

string to_string(char ch) {
    return "'" + string(1, ch) + "'"; 
}

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

class IterateOverACube {
public:
    vector <int> findCell(int N, long long index) {
        auto add = [&](vector<long long> &x, int l, int r, long long val) {
            x[l] += val;
            if (r + 1 < x.size()) {
                x[r + 1] -= val;
            }
        };
        vector<long long> cnt2(2 * N - 1);
        for (int i = 0; i < N; ++i) {
            add(cnt2, i, i + N - 1, 1);      
        }
        for (int i = 1; i < cnt2.size(); ++i) {
            cnt2[i] += cnt2[i - 1];
        }
        vector<long long> cnt3(3 * N - 2);
        for (int i = 0; i < cnt2.size(); ++i) {
            add(cnt3, i, i + N - 1, cnt2[i]);
        }
        for (int i = 1; i < cnt3.size(); ++i) {
            cnt3[i] += cnt3[i - 1];
        }
        ++index;
        for (int sum = 0; sum < cnt3.size(); ++sum) {
            if (index > cnt3[sum]) {
                index -= cnt3[sum];
            } else {
                for (int pt1 = 0; pt1 < N; ++pt1) {
                    int rem2 = sum - pt1;
                    if (rem2 >= cnt2.size()) {
                        continue;
                    } else if (index > cnt2[rem2]) {
                        index -= cnt2[rem2];
                    } else {
                        for (int pt2 = 0; pt2 < N; ++pt2) {
                            int rem3 = sum - pt1 - pt2;
                            if (rem3 >= N) {
                                continue;
                            } else if (index > 1) {
                                --index;
                            } else {
                                return vector<int>{pt1, pt2, sum - pt1 - pt2};
                            }
                        }
                    }
                }
            }
        }
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
			int N                     = 3;
			long long index           = 9;
			int expected__[]          = {2, 0, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			long long index           = 10;
			int expected__[]          = {0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 4747;
			long long index           = 106968940722LL;
			int expected__[]          = {4746, 4746, 4746 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 4;
			long long index           = 32;
			int expected__[]          = {0, 2, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}


      case 4: {

			int N                     = 1000000;
			long long index           = 100000000000000;
			int expected__[]          = {12109, 28955, 43278};

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
/*      case 5: {
			int N                     = ;
			long long index           = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			long long index           = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = IterateOverACube().findCell(N, index);
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
