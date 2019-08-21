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

const pair<int, int> none = {-1, -1};

void test_case() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n + 1, vector<int>(n + 1));
  vector<vector<pair<int, int>>> cnt(n + 1, vector<pair<int, int>>(n + 1));
  auto get_cnt = [&](int r, int c, int f) {
    int foo = grid[r][c];
    int ret = 0;
    while (foo % f == 0) {
      foo /= f;
      ++ret;
    }
    return ret;
  };
  auto zero = none;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 0) {
        zero = {i, j};
        grid[i][j] = 10;
      }
      cnt[i][j] = {get_cnt(i, j, 2), get_cnt(i, j, 5)};
    }
  }
  vector<vector<int>> dp2(n + 1, vector<int>(n + 1, -1));
  vector<vector<pair<int, int>>> trans2(n + 1, vector<pair<int, int>>(n + 1, none));
  vector<vector<int>> dp5(n + 1, vector<int>(n + 1, -1));
  vector<vector<pair<int, int>>> trans5(n + 1, vector<pair<int, int>>(n + 1, none));
  function<int(int, int, int)> solve = [&](int r, int c, int st) {
    int ans = (st == 2 ? dp2[r][c] : dp5[r][c]);
    if (ans == -1) {
      ans = (st == 2 ? cnt[r][c].first : cnt[r][c].second);
      pair<int, int> nxt = none;
      int to_add = -1;
      if (c + 1 <= n) {
        auto right = solve(r, c + 1, st);
        to_add = right;
        nxt = {r, c + 1};
      }
      if (r + 1 <= n) {
        auto down = solve(r + 1, c, st);
        if (to_add == -1 || down < to_add) {
          to_add = down;
          nxt = {r + 1, c};
        }
      }
      if (to_add != -1) {
        ans += to_add;
      }
      (st == 2 ? dp2[r][c] : dp5[r][c]) = ans;
      (st == 2 ? trans2[r][c] : trans5[r][c]) = nxt;
    }
    return (st == 2 ? dp2[r][c] : dp5[r][c]);
  };
  auto ans2 = solve(1, 1, 2);
  auto ans5 = solve(1, 1, 5);
  if (zero == none || min(ans2, ans5) == 0) {
    cout << min(ans2, ans5) << "\n";
    pair<int, int> pos = {1, 1};
    while (pos != make_pair(n, n)) {
      auto nxt = (ans2 < ans5 ? trans2[pos.first][pos.second] : trans5[pos.first][pos.second]);
      if (nxt.first == pos.first) {
        cout << "R";
      } else {
        cout << "D";
      }
      pos = nxt;
    }
  } else {
    cout << "1\n";
    pair<int, int> pos = {1, 1};
    while (pos.first != zero.first) {
      cout << "D";
      ++pos.first;
    }
    while (pos.second != zero.second) {
      cout << "R";
      ++pos.second;
    }
    while (pos.first != n) {
      cout << "D";
      ++pos.first;
    }
    while (pos.second != n) {
      cout << "R";
      ++pos.second;
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
