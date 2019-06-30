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
	vector<int> d(n + 1);
	vector<pair<int, int>> ends, o;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		if (d[i] == 1) {
			ends.push_back({d[i], i});
		} else {
			o.push_back({d[i], i});
		}
	}
	sort(o.rbegin(), o.rend());
	if (o.empty()) {
		cout << "NO\n";
	} else {
		while (ends.size() < 2) {
			ends.push_back(o.back());
			o.pop_back();
		}
		vector<pair<int, int>> edges;
		int dia = o.size() + 1;
		auto add_edge = [&](int a, int b) {
			edges.push_back({a, b});
			--d[a];
			--d[b];
		};
		add_edge(ends.front().second, o.front().second);
		add_edge(ends.back().second, o.back().second);
		for (int i = 0; i + 1 < o.size(); ++i) {
			add_edge(o[i].second, o[i + 1].second);
		}
		int ctr_o = 0, ctr_e = 1;
		while (ctr_e <= ends.size() - 2 && ctr_o < o.size()) {
			if (d[o[ctr_o].second] > 0) {
				add_edge(o[ctr_o].second, ends[ctr_e++].second);
			} else {
				++ctr_o;
			}
		}
		if (edges.size() != n - 1) {
			cout << "NO\n";
		} else {
			cout << "YES " << dia << "\n";
			cout << edges.size() << "\n";
			for (auto [u, v] : edges) {
				cout << u << " " << v << "\n";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	test_case();
	return 0;
}