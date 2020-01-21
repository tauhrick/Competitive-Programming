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

const int N = 3e5 + 10, INF = INT_MAX;


class Segment_tree {
public:
	struct Node {
		int mn;

		Node() : mn(INF) {}

		Node(int _mn) : mn(_mn) {}

		void apply(int v) {
			mn = v;
		}
	};

	Node unite(const Node& a, const Node& b) {
		return Node(min(a.mn, b.mn));
	}

	void pull(int tv, int lc, int rc) {
		Tree[tv] = unite(Tree[lc], Tree[rc]);
	}

	void push(int tv, int lc, int tr) {
		//
	}

	int n;
	vector<Node> Tree;

	Segment_tree(int _n) : n(_n) {
		Tree.resize(4 * n + 4);
		build(1, 1, n);
	}

	template <typename M>
	Segment_tree(const vector<M>& V) {
		n = V.size();
		assert(n > 0);
		Tree.resize(4 * n + 4);
		build(1, 1, n, V);
	}

	void build(int tv, int tl, int tr) {
		if (tl == tr) {
			return;
		} else {
			int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
			build(lc, tl, tm);
			build(rc, tm + 1, tr);
			pull(tv, lc, rc);
		}
	}

	template <typename M>
	void build(int tv, int tl, int tr, const vector<M>& V) {
		if (tl == tr) {
			Tree[tv].apply(V[tl]);
		} else {
			int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
			build(lc, tl, tm, V);
			build(rc, tm + 1, tr, V);
			pull(tv, lc, rc);
		}
	}

	template <typename M>
	void modify(int tv, int tl, int tr, int ql, int qr, const M& v) {
		if (qr < tl || tr < ql) {
			return;
		} else if (ql <= tl && tr <= qr) {
			Tree[tv].apply(v);
		} else {
			int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
			push(tv, lc, rc);
			modify(lc, tl, tm, ql, qr, v);
			modify(rc, tm + 1, tr, ql, qr, v);
			pull(tv, lc, rc);
		}
	}

	Node get(int tv, int tl, int tr, int ql, int qr) {
		if (qr < tl || tr < ql) {
			return Node(INF);
		} else if (ql <= tl && tr <= qr) {
			return Tree[tv];
		} else {
			int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
			push(tv, lc, rc);
			return unite(get(lc, tl, tm, ql, qr), get(rc, tm + 1, tr, ql, qr));
		}
	}

	template <typename M>
	void modify(int p, const M& v) {
		modify(1, 1, n, p, p, v);
	}

	template <typename M>
	void modify(int ql, int qr, const M& v) {
		modify(1, 1, n, ql, qr, v);
	}

	Node get(int p) {
		return get(1, 1, n, p, p);
	}

	Node get(int ql, int qr) {
		return get(1, 1, n, ql, qr);
	}
};


void test_case() {
	int n;
	cin >> n;
	vector<int> A(n + 1), B(n + 1);
	vector<pair<int, vector<int>>> Pos(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> A[i];
		Pos[A[i]].second.emplace_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> B[i];
	}
	Segment_tree sg(A);
	for (int i = 1; i <= n; ++i) {
		if (Pos[B[i]].first == Pos[B[i]].second.size()) {
			cout << "NO\n";
			return;
		}
		int pos = Pos[B[i]].second[Pos[B[i]].first++];
		if (sg.get(1, pos).mn == B[i]) {
			sg.modify(pos, INF);
		} else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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