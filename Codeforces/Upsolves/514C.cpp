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

int nxt[3][N];
bool is_end[N];
int done = 0;

void insert_trie(string& s) {
  int ind = 0;
  for (auto c : s) {
    int e = c - 'a';
    if (nxt[e][ind] == 0) {
      nxt[e][ind] = ++done;
    }
    ind = nxt[e][ind];
  }
  is_end[ind] = true;
}

bool solve(string&s, int len_ctr = 0, bool changed = false, int nxt_ctr = 0) {
  if (len_ctr == (int) s.size()) {
    if (changed) {
      return is_end[nxt_ctr];
    } else {
      return false;
    }
  }
  bool ret = false;
  int e = s[len_ctr] - 'a';
  if (nxt[e][nxt_ctr] != 0) {
    ret |= solve(s, len_ctr + 1, changed, nxt[e][nxt_ctr]);
  }
  if (!changed) {
    for (int o = 0; o < 3; ++o) {
      if (o != e && nxt[o][nxt_ctr] != 0) {
        ret |= solve(s, len_ctr + 1, true, nxt[o][nxt_ctr]);
      }
    }
  }
  return ret;
}

void test_case() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    insert_trie(s);
  }
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    if (solve(s)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
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
