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
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<vector<int>> pref(26, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		pref[s[i] - 'a'][i] = 1;
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref[i][j] += pref[i][j - 1];
		}
	}
	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		map<int,int> cnt;
		for (auto ch : t) {
			++cnt[ch - 'a'];
		}
		int st = -1;
		for (auto e : cnt) {
			st = max(st, int(lower_bound(pref[e.first].begin(), pref[e.first].end(), e.second) - pref[e.first].begin()));
		}
		cout << st << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}