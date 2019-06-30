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
	long long n;
	int q;
	cin >> n >> q;
	set<pair<long long, long long>> ranges;
	set<long long> done;
	long long s = 0;
	while (q--) {
		int typ;
		cin >> typ;
		debug(ranges);
		debug(s);
		if (typ == 1) {
			long long x;
			cin >> x;
			x += s;
			if (done.count(x)) {
				continue;
			}
			done.insert(x);
			debug(x);
			auto up = ranges.lower_bound({x, -1});
			if (up != ranges.end()) {
				auto r_up = *up;
				if (r_up.second == x + 1) {
					ranges.erase(up);
					ranges.insert({r_up.first, x});
				} else {
					ranges.insert({x, x});
				}
			} else {
				ranges.insert({x, x});
			}
			auto nxt = ranges.lower_bound({x, -1});
			auto lo = --ranges.lower_bound({x, -1});
			if (nxt != ranges.begin()) {
				auto r_lo = *lo;
				auto r_nxt = *nxt;
				if (r_lo.first == r_nxt.second - 1) {
					ranges.erase(nxt);
					ranges.erase(lo);
					ranges.insert({r_nxt.first, r_lo.second});
				}
			}
		} else if (typ == 2) {
			long long l, r;
			cin >> l >> r;
			l += s;
			r += s;
			debug(l, r);
			long long ans = 0;
			auto it = ranges.lower_bound({r, -1});
			if (it == ranges.end()) {
				ans = r;
			} else {
				auto rg = *it;
				if (rg.second > l) {
					ans = min(rg.second - 1, r);
				}
			}
			cout << ans << "\n";
			s += ans;
			s %= n;
		} else {
			assert(false);
		}
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