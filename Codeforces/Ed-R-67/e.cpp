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

void test_case() {
	int n;
	cin >> n;
	vector<vector<int>> G(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	vector<int> sz(n + 1);
	function<void(int, int)> dfs_sz = [&](int u, int p) {
		sz[u] = 1;
		for (auto v : G[u]) {
			if (v != p) {
				dfs_sz(v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs_sz(1, 0);
	long long ans = accumulate(sz.begin() + 1, sz.end(), 0LL);
	function<void(int, int, long long)> dfs = [&](int u, int p, long long curr) {
		ans = max(ans, curr);
		for (auto v : G[u]) {
			if (v != p) {
				dfs(v, u, curr - sz[v] + n - sz[v]);
			}
		}
	};
	dfs(1, 0, ans);
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}