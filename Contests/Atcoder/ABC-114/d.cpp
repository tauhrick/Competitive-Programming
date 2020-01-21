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
	cin >> n;
	map<int, int> cnt;
	for (int i = 1; i <= n; ++i) {
		int x = i;
		for (int f = 2; f * f <= x; ++f) {
			while (x % f == 0) {
				++cnt[f];
				x /= f;
			}
		}
		if (x != 1) {
			++cnt[x];
		}
	}
	debug(cnt);
	vector<pair<int, int>> v_cnt;
	for (auto i : cnt) {
		v_cnt.push_back(i);
	}
	set<long long> unq;
	function<void(int, int, long long)> solve = [&](int ind, int num, long long x) {
		if (num == 1) {
			unq.insert(x);
			return;
		} else if (ind == v_cnt.size()) {
			return;
		}
		long long p = 1; 
		for (int take = 0; take <= v_cnt[ind].second; ++take) {
			if (num % (take + 1) == 0) {
				solve(ind + 1, num / (take + 1), x * p);
			}
			p *= v_cnt[ind].first;
		}
	};
	solve(0, 75, 1);
	cout << unq.size() << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}