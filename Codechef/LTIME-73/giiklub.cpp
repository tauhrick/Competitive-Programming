#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
	return '"' + s + '"';
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

const int N = 21, M = 1e5 + 1;

int n;
long long grid[N][N];
long long dp[N][N][M];

long long ways(int r, int c, long long rem) {
	if (r == n && c == n) {
		return 1;
	}
	auto& ans = dp[r][c][rem];
	if (ans == -1) {
		ans = 0;
		rem -= grid[r][c];
		if (r + 1 <= n && rem - grid[r + 1][c] >= 0) {
			ans += ways(r + 1, c, rem);
		}
		if (c + 1 <= n && rem - grid[r][c + 1] >= 0) {
			ans += ways(r, c + 1, rem);
		}
	}
	return ans;
}

void test_case() {
	long long x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> grid[i][j];
		}
	}
	if (n > 10) {
		memset(dp, -1, sizeof dp);
		cout << ways(1, 1, x) << "\n";
	} else {
		long long ans = 0;
		int len = 2 * (n - 1);
		for (int mask = 0; mask < (1 << len); ++mask) {
			if (__builtin_popcount(mask) == len / 2) {
				int r = 1, c = 1;
				long long tot = grid[r][c];
				for (int i = 0; i < len; ++i) {
					if (mask & (1 << i)) {
						tot += grid[++r][c];
					} else {
						tot += grid[r][++c];
					}
				}
				assert(r == n && c == n);
				ans += tot <= x;
			}
		}
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		test_case();
	}
	return 0;
}