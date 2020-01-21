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

void test_case() {
  int n;
  cin >> n;
  vector<vector<int>> G(n + 1);
  for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char ch;
			cin >> ch;
			if (ch == '1') {
				G[i].emplace_back(j);
			}
		}
	}
	vector<vector<int>> dist(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		vector<bool> seen(n + 1);
		queue<pair<int, int>> q;
		q.push({i, 1});
		while (!q.empty()) {
			auto [x, d] = q.front();
			q.pop();
			if (seen[x]) {
				continue;
			}
			seen[x] = true;
			dist[i][x] = d;
			for (auto y : G[x]) {
				if (!seen[y]) {
					q.push({y, d + 1});
				}
			}
		}
	}
	int m;
	cin >> m;
	vector<int> P(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> P[i];
	}
	vector<pair<int, int>> res = {{P[1], 1}};
	int l = 2;
	while (true) {
		bool ok = true;
		auto [u, pos] = res.back();
		for (int ctr = l; ctr <= m; ++ctr) {
			int tar = ctr - pos + 1;
			if (dist[u][P[ctr]] < tar) {
				ok = false;
				l = ctr;
				res.emplace_back(P[ctr - 1], ctr - 1);
				break;
			}
		}
		if (ok) {
			res.emplace_back(P[m], m);
			break;
		}
	}
	cout << res.size() << "\n";
	for (auto [x, _] : res) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
