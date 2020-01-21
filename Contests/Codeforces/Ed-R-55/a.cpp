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
	int n, x, y, d;
	cin >> n >> x >> y >> d;
	int st = min(x, y);
	int en = max(x, y);
	int moves = INT_MAX;
	if ((en - st) % d == 0) {
		moves = min(moves, (en - st) / d);
	}
	if ((y - 1) % d == 0) {
		moves = min(moves, (x - 1 + d - 1) / d + (y - 1) / d);
	}
	if ((n - y) % d == 0) {
		moves = min(moves, (n - x + d - 1) / d + (n - y) / d);
	}
	if (moves == INT_MAX) {
		cout << "-1\n";
	} else {
		cout << moves << "\n";
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