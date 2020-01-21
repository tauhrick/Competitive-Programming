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
  long long sum;
  Node* l;
  Node* r;
  
  Node(long long _sum = 0, Node* _l = nullptr, Node* _r = nullptr) {
    sum = _sum;
    l = _l;
    r = _r;
  }
};

const long long N = 1e18;

void update(Node* curr, long long tl, long long tr, long long x, long long val) {
  auto& node = *curr;
  if (tl == tr) {
    node.sum = val;
  } else {
    long long tm = tl + tr >> 1;
    if (x <= tm) {
      if (node.l == nullptr) {
        node.l = new Node();
      }
      update(node.l, tl, tm, x, val);
    } else {
      if (node.r == nullptr) {
        node.r = new Node();
      }
      update(node.r, tm + 1, tr, x, val);
    }
    node.sum = 0;
    if (node.l != nullptr) {
      node.sum += (*(node.l)).sum;
    }
    if (node.r != nullptr) {
      node.sum += (*(node.r)).sum;
    }
  }
}

long long get(Node* curr, long long tl, long long tr, long long ql, long long qr) {
  auto& node = *curr;
  if (qr < tl || tr < ql) {
    assert(false);
  } else if (ql <= tl && tr <= qr) {
    return node.sum;
  } else {
    long long tm = tl + tr >> 1;
    long long ret = 0;
    if (qr < tl || tm < ql) {
    } else {
      if (node.l != nullptr) {
        ret += get(node.l, tl, tm, ql, qr);
      }
    }
    if (qr < tm + 1 || tr < ql) {
    } else {
      if (node.r != nullptr) {
        ret += get(node.r, tm + 1, tr, ql, qr);
      }
    }
    return ret;
  }
}

void test_case() {
  int q;
  long long m1, m2;
  cin >> q >> m1 >> m2;
  Node* head = new Node();
  long long prv_ans = 0;
  while (q--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      long long a, b;
      cin >> a >> b;
      long long x = (a + prv_ans) % m1 + 1;
      long long y = (b + prv_ans) % m2 + 1;
      update(head, 1, N, x, y);
    } else {
      long long a;
      cin >> a;
      long long x = (a + prv_ans) % m1 + 1;
      prv_ans = get(head, 1, N, 1, x);
      cout << prv_ans << "\n";
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
