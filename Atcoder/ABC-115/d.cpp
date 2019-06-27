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

vector<long long> sz, p;

long long solve(int lvl, long long rem) {
	if (rem <= 1) {
		return 0;
	}
	--rem;
	long long ans = 0;
	if (sz[lvl - 1] <= rem) {
		rem -= sz[lvl - 1];
		ans += p[lvl - 1];
	} else {
		return solve(lvl - 1, rem);
	}
	if (rem == 0) {
		return ans;
	}
	++ans;
	--rem;
	if (rem == 0) {
		return ans;
	}
	if (sz[lvl - 1] <= rem) {
		rem -= sz[lvl - 1];
		ans += p[lvl - 1];
	} else {
		return ans + solve(lvl - 1, rem);
	}
	--rem;
	return ans;
}

void test_case() {
	int n;
	long long x;
	cin >> n >> x;
	sz.resize(n + 1);
	p.resize(n + 1);
	sz[0] = 1, p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		sz[i] = 3 + 2 * sz[i - 1];
		p[i] = 1 + 2 * p[i - 1];
	}
	cout << solve(n, x) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}