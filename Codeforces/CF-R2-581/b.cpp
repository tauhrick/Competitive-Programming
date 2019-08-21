#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
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
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> mn(n + 1);
  int rem = l - 1;
  for (int i = rem + 1; i <= n; ++i) {
		mn[i] = 1;
	}
	for (int i = rem, nxt = 2; i >= 1; --i, nxt *= 2) {
		mn[i] = nxt;
	}
	vector<int> mx(n + 1);
	for (int i = 1, unq = 0, nxt = 1; i <= n; ++i) {
		mx[i] = nxt;
		++unq;
		if (unq < r) {
			nxt *= 2;
		}
	}
	cout << accumulate(mn.begin(), mn.end(), 0) << " " << accumulate(mx.begin(), mx.end(), 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
