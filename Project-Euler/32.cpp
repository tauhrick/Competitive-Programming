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
	set<int> products;
	for (int mask = 1; mask < (1 << 9); ++mask) {
		string s;
		for (int i = 0; i < 9; ++i) {
			if (mask & (1 << i)) {
				s += '0' + i + 1;
			}
		}
		if (s.size() > 7) {
			continue;
		}
		do {
			int p = stoi(s);
			for (int f = 2; f * f <= p; ++f) {
				if (p % f == 0) {
					string t = s + to_string(f) + to_string(p / f);
					vector<int> cnt(10);
					for (auto ch : t) {
						++cnt[ch - '0'];
					}
					if (cnt[0]) {
						continue;
					}
					bool ok = true;
					for (int i = 1; i <= 9; ++i) {
						if (cnt[i] != 1) {
							ok = false;
						}
					}
					if (ok) {
						products.insert(p);
						break;
					}
				}
			}
		} while (next_permutation(s.begin(), s.end()));
	}
	cout << accumulate(products.begin(), products.end(), 0) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}