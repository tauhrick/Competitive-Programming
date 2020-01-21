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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> skills(m + 1);
	for (int i = 0; i < n; ++i) {
		int s, r;
		cin >> s >> r;
		skills[s].push_back(r);
	}
	vector<vector<int>> pre(m + 1);
	for (int i = 1; i <= m; ++i) {
		sort(skills[i].rbegin(), skills[i].rend());
		pre[i].resize(skills[i].size() + 1);
		pre[i][0] = 0;
		for (int j = 0; j < skills[i].size(); ++j) {
			pre[i][j + 1] = pre[i][j] + skills[i][j];
		}
	}
	debug(skills);
	debug(pre);
	set<int> rem;
	for (int i = 1; i <= m; ++i) {
		rem.insert(i);
	}
	int res = 0;
	for (int take = 1; take <= n; ++take) {
		vector<int> buff;
		int curr = 0;
		for (auto sub : rem) {
			if (take >= pre[sub].size()) {
				buff.push_back(sub);
			} else {
				curr += max(0, pre[sub][take]);
			}
		}
		res = max(res, curr);
		for (auto sub : buff) {
			rem.erase(sub);
		}
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}