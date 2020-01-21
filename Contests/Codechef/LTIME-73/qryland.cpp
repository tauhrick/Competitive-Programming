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

const int N = 1e5 + 10, INF = INT_MAX;

int n;
vector<int> g[N];
int a[N], par[N];

void dfs(int u, int p, int e) {
	par[u] = p;
	if (u == e) {
		return;
	}
	for (auto &v: g[u]) {
		if (v != p) {
			dfs(v, u, e);
		}
	}
}

void test_case() {
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while (q--) {
		int typ;
		cin >> typ;
		if (typ == 1) {
			int x, y;
			cin >> x >> y;
			dfs(x, 0, y);
			vector<int> path;
			int node = y;
			while (node != 0) {
				path.push_back(a[node]);
				node = par[node];
			}
			sort(path.begin(), path.end());
			bool ok = true;
			for (int i = 0; i < path.size(); ++i) {
				if (path[i] != i + 1) {
					ok = false;
				}
			}
			cout << (ok ? "Yes\n" : "No\n");
		} else if (typ == 2) {
			int x, z;
			cin >> x >> z;
			a[x] = z;
		} else {
			assert(false);
		}
	}
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
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