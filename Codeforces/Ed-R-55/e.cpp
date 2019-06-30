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

const int N = 5e5 + 10;

vector<int> pos[N];

void test_case() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	auto get_cnt = [](int l, int r, int x) {
		if (l > r) {
			return 0;
		}
		int hi = (upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin()) - 1;
		int lo = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
		return hi - lo + 1;
	};
	int res = 0, prv = 0;
	for (int i = 1; i <= n; ++i) {
		int lo = i, hi = n, mid;
		while (lo < hi) {
			mid = lo + (hi - lo + 1 >> 1);
			if (get_cnt(i, mid, a[i]) - get_cnt(i, mid, c) >= 0) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		res = max(res, prv + get_cnt(i, lo, a[i]) + get_cnt(lo + 1, n, c));
		prv += a[i] == c;
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