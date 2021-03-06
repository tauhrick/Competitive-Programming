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
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	int m;
	cin >> m;
	vector<int> diff(n + 2);
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		++diff[a];
		--diff[n - a + 1 + 1];
	}
	for (int i = 1; i <= n; ++i) {
		diff[i] += diff[i - 1];
	}
	for (int i = 1; i <= n / 2; ++i) {
		if (diff[i] & 1) {
			swap(s[i], s[n - i + 1]);
		}
	}
	cout << s.substr(1) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}