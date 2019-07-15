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

const int N = 1e6 + 10;

int n;
int A[N];
int f;
deque<int> dq;
pair<long long, int> ans, none = {LLONG_MAX, -1};

void update_ans(int to_add, int pos) {
  int nxt = pos;
  if (nxt == n) {
    nxt = 1;
  }
  if (A[nxt] > f) {
    return;
  }
  long long hits = to_add + f;
  int sz = dq.size(), ctr = sz - 1, iter = 0;
  while (sz != 1) {
    if (sz & 1) {
      hits += dq[ctr];
    } else {
      ctr -= (1 << iter);
    }
    sz = (sz + 1) / 2;
    ++iter;
  }
  ans = min(ans, make_pair(hits, pos));
}

void test_case() {
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> A[i];
    dq.push_back(A[i]);
  }
  cin >> f;
  ans = none;
  update_ans(0, 1);
  for (int p = 1; p <= n - 1; ++p) {
    dq.pop_front();
    int to_add = 0;
    if (p & 1) {
      dq.push_back(A[p]);
      to_add = A[p];
    }
    update_ans(to_add, p + 1);
  }
  if (ans == none) {
    cout << "impossible\n";
  } else {
    cout << "possible\n";
    cout << ans.second << " " << ans.first << "\n";
  }
  dq.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
