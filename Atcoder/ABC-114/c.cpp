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
	vector<int> nums;
	function<void(int, int, int, int, int)> solve = [&](int dig, int x, int c1, int c2, int c3) {
		if (dig == 10) {
			return;
		} else {
			if (c1 > 0 && c2 > 0 && c3 > 0) {
				nums.push_back(x);
			}
			solve(dig + 1, x * 10 + 7, c1 + 1, c2, c3);
			solve(dig + 1, x * 10 + 5, c1, c2 + 1, c3);
			solve(dig + 1, x * 10 + 3, c1, c2, c3 + 1);
		}
	};
	solve(0, 0, 0, 0, 0);
	sort(nums.begin(), nums.end());
	nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));
	int n;
	cin >> n;
	cout << upper_bound(nums.begin(), nums.end(), n) - nums.begin() << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}