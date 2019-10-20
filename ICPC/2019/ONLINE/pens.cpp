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

const int N = 2e6 + 10, M = 3e6 + 10;

int n, k;
int dp[M];
int get_pos[M];
string s;

void clear_data() {
  memset(dp, 0, sizeof dp);
}

int solve(int hash) {
  //~ debug(hash, dp[hash]);
  return dp[hash];
}

void test_case() {
  cin >> n >> k >> s;
  for (int i = 0; i < k; ++i) {
    string t;
    cin >> t;
    int hash = 0;
    for (auto ch : t) {
      hash |= (1 << (ch - 'a'));
    }
    dp[hash] = i + 1;
  }
  for (int mask = (1 << 20) - 1; mask > 0; --mask) {
    for (int i = mask; i < (1 << 20); ) {
      int z = ~i & (i + 1);
      int pos = get_pos[z];
      //~ debug(pos);
      i = i | (1 << pos);
      if (i < (1 << 20)) {
        dp[mask] = max(dp[mask], dp[mask | (1 << pos)]);
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < n; ) {
    int hash = 0;
    int st = i;
    while (i < n) {
      int ind = solve(hash | (1 << (s[i] - 'a')));
      if (ind == 0) {
        break;
      } else {
        hash |= (1 << (s[i] - 'a'));
      }
      //~ debug(i, hash);
      ++i;
    }
    int ind = solve(hash);
    for (int j = st; j < i; ++j) {
      cout << ind << " ";
    }
    //~ debug(i);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  get_pos[1] = 0;
  for (int i = 2; i < M; i *= 2) {
    get_pos[i] = get_pos[i / 2] + 1;
  }
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    clear_data();
    test_case();
  }
  return 0;
}
