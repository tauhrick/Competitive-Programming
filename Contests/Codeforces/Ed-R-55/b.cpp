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
	vector<pair<int, int>> v;
	int cnt = 0;
	for (auto ch : s) {
		cnt += ch == 'G';
	}
	if (s.front() == 'S') {
		v.push_back({0, -1});
	}
	for (int i = 0; i < n; ) {
		int st = i, len = 0;
		while (i < n && s[i] == s[st]) {
			++i;
			++len;
		}
		v.push_back({len, st});
	}
	int res = 0;
	for (int i = 0; i < v.size(); i += 2) {
		if (v[i].second == -1) {
			continue;
		}
		res = max(res, v[i].first);
		if (i + 2 < v.size() && v[i].second + v[i].first - 1 == v[i + 2].second - 2) {
			res = max(res, min(cnt, v[i].first + v[i + 2].first + 1));
		}
		if (v.size() != 1) {
			res = max(res, min(cnt, v[i].first + 1));
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