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
	int n, d;
	cin >> n >> d;
	vector<int> p(n + 1), pos(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	int swaps = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == p[i]) {
			continue;
		}
		int diff = p[i] - i;
		if (diff % d != 0) {
			cout << "-1\n";
			return;
		}
		int m = diff / d;
		swaps += m;
		for (int nxt = 1; nxt <= m; ++nxt) {
			swap(p[pos[i]], p[pos[i + nxt * d]]);
			swap(pos[i], pos[i + nxt * d]);
		}
	}
	cout << swaps << "\n";
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