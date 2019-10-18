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

struct Node {
  int mx;
  int ans;
  int lazy;

  Node(int _mx = INT_MIN, int _ans = INT_MAX) {
    mx = _mx;
    ans = _ans;
    lazy = INT_MAX;
  }
};

const int N = 3e5 + 10;

int n;
int A[N];
Node sg[4 * N];

void push(int tv, int lc, int rc) {
  if (sg[tv].lazy != INT_MAX) {
    sg[lc].ans = min(sg[lc].ans, sg[tv].lazy);
    sg[lc].lazy = min(sg[lc].lazy, sg[tv].lazy);
    sg[rc].ans = min(sg[rc].ans, sg[tv].lazy);
    sg[rc].lazy = min(sg[rc].lazy, sg[tv].lazy);
    sg[tv].lazy = INT_MAX;
  }
}

Node unite(Node a, Node b) {
  return Node(max(a.mx, b.mx), min(a.ans, b.ans));
}

void build(int tv = 1, int tl = 1, int tr = 3 * n) {
  if (tl == tr) {
    sg[tv].mx = A[tl];
  } else {
    int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
    build(lc, tl, tm);
    build(rc, tm + 1, tr);
    sg[tv] = unite(sg[lc], sg[rc]);
  }
}

Node get(int ql, int qr, int tv = 1, int tl = 1, int tr = 3 * n) {
  if (qr < tl || ql > tr) {
    return Node();
  } else if (ql <= tl && tr <= qr) {
    return sg[tv];
  } else {
    int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
    push(tv, lc, rc);
    return unite(get(ql, qr, lc, tl, tm), get(ql, qr, rc, tm + 1, tr));
  }
}

void modify(int ql, int qr, int v, int tv = 1, int tl = 1, int tr = 3 * n) {
  if (qr < tl || ql > tr) {
    return;
  } else if (ql <= tl && tr <= qr) {
    sg[tv].ans = min(sg[tv].ans, v);
    sg[tv].lazy = min(sg[tv].lazy, v);
  } else {
    int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
    push(tv, lc, rc);
    modify(ql, qr, v, lc, tl, tm);
    modify(ql, qr, v, rc, tm + 1, tr);
    sg[tv] = unite(sg[lc], sg[rc]);
  }
}

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    A[n + i] = A[2 * n + i] = A[i];
  }
  build();
  for (int i = 2 * n; i >= 2; --i) {
    int lo = 1, hi = i - 1, mid;
    while (lo < hi) {
      mid = lo + (hi - lo + 1 >> 1);
      int mx = get(mid, i - 1).mx;
      if (A[i] * 2 < mx) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    if (A[i] * 2 < get(lo, i - 1).mx)  {
      modify(1, lo, i);
    }
  }
  int mx = *max_element(A + 1, A + 1 + n);
  int ind = 2 * n + 1;
  while (ind <= 3 * n && !(A[ind] * 2 < mx)) {
    ++ind;
  }
  int o = (ind == 3 * n + 1 ? INT_MAX : ind);
  for (int i = 1; i <= n; ++i) {
    int ans = get(i, i).ans;
    ans = min(ans, o);
    if (ans == INT_MAX) {
      cout << "-1 ";
    } else {
      cout << ans - i << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
