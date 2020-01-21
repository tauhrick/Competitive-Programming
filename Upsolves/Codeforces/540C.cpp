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

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

void test_case() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> grid[i];
    grid[i] = " " + grid[i];
  }
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int cnt = 0;
  for (int dr = 0; dr < 4; ++dr) {
    int r = r2 + dy[dr];
    int c = c2 + dx[dr];
    if (r >= 1 && r <= n && c >= 1 && c <= m && grid[r][c] == '.') {
      ++cnt;
    }
  }
  if (r1 == r2 && c1 == c2) {
    if (cnt == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
    return;
  } else if (grid[r2][c2] == '.') {
    if (abs(r2 - r1) + abs(c2 - c1) == 1) {
      if (cnt < 1) {
        cout << "NO\n";
        return;
      }
    } else {
      if (cnt < 2) {
        cout << "NO\n";
        return;
      }
    }
  }
  vector<vector<bool>> seen(n + 1, vector<bool>(m + 1));
  queue<pair<int, int>> q;
  q.push({r1, c1});
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    if (seen[r][c]) {
      continue;
    }
    seen[r][c] = true;
    for (int dr = 0; dr < 4; ++dr) {
      int _r = r + dy[dr];
      int _c = c + dx[dr];
      if (_r >= 1 && _r <= n && _c >= 1 && _c <= m && !seen[_r][_c]) {
        if (_r == r2 && _c == c2) {
          cout << "YES\n";
          return;
        } else if (grid[_r][_c] == '.') {
          q.push({_r, _c});
        }
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
