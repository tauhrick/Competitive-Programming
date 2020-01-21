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
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
  n = v.size();
  if (n > 16) {
    cout << "grid\nsnot\nposs\nible\n";
  } else {
    vector<int> r_l(4), r_r(4), c_u(4), c_d(4);
    vector<vector<char>> grid(4, vector<char>(4, '#'));
    string ans;
    function<void(int)> solve = [&](int ind) {
      if (ind == (int) v.size()) {
        string curr;
        for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == '#') {
              grid[i][j] = 'A';
            }
            curr += grid[i][j];
          }
        }
        if (ans.size() == 0) {
          ans = curr;
        } else {
          ans = min(ans, curr);
        }
      } else {
        for (int i = 0; i < 4; ++i) {
          if (r_l[i] == 0) {
            bool ok = true;
            for (int c = 0; c < 4; ++c) {
              if (grid[i][c] != '#' && grid[i][c] != v[ind][c]) {
                ok = false;
              }
            }
            if (ok) {
              vector<char> buff(4);
              for (int c = 0; c < 4; ++c) {
                buff[c] = grid[i][c];
                grid[i][c] = v[ind][c];
              }
              r_l[i] = 1;
              solve(ind + 1);
              r_l[i] = 0;
              for (int c = 0; c < 4; ++c) {
                grid[i][c] = buff[c];
              }
            }
          }
        }
        for (int i = 0; i < 4; ++i) {
          if (r_r[i] == 0) {
            bool ok = true;
            for (int c = 3, j = 0; c >= 0; --c, ++j) {
              if (grid[i][c] != '#' && grid[i][c] != v[ind][j]) {
                ok = false;
              }
            }
            if (ok) {
              vector<char> buff(4);
              for (int c = 3, j = 0; c >= 0; --c, ++j) {
                buff[c] = grid[i][c];
                grid[i][c] = v[ind][j];
              }
              r_r[i] = 1;
              solve(ind + 1);
              r_r[i] = 0;
              for (int c = 3, j = 0; c >= 0; --c, ++j) {
                grid[i][c] = buff[c];
              }
            }
          }
        }
        for (int i = 0; i < 4; ++i) {
          if (c_u[i] == 0) {
            bool ok = true;
            for (int r = 0, j = 0; r < 4; ++r, ++j) {
              if (grid[r][i] != '#' && grid[r][i] != v[ind][j]) {
                ok = false;
              }
            }
            if (ok) {
              vector<char> buff(4);
              for (int r = 0, j = 0; r < 4; ++r, ++j) {
                buff[r] = grid[r][i];
                grid[r][i] = v[ind][j];
              }
              c_u[i] = 1;
              solve(ind + 1);
              c_u[i] = 0;
              for (int r = 0, j = 0; r < 4; ++r, ++j) {
                grid[r][i] = buff[r];
              }
            }
          }
        }
        for (int i = 0; i < 4; ++i) {
          if (c_d[i] == 0) {
            bool ok = true;
            for (int r = 3, j = 0; r >= 0; --r, ++j) {
              if (grid[r][i] != '#' && grid[r][i] != v[ind][j]) {
                ok = false;
              }
            }
            if (ok) {
              vector<char> buff(4);
              for (int r = 3, j = 0; r >= 0; --r, ++j) {
                buff[r] = grid[r][i];
                grid[r][i] = v[ind][j];
              }
              c_d[i] = 1;
              solve(ind + 1);
              c_d[i] = 0;
              for (int r = 3, j = 0; r >= 0; --r, ++j) {
                grid[r][i] = buff[r];
              }
            }
          }
        }
      }
    };
    solve(0);
    if (ans.size() == 16) {
      for (int st = 0; st < 16; st += 4) {
        cout << ans.substr(st, 4) << "\n";
      }
    } else {
      cout << "grid\nsnot\nposs\nible\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    test_case();
    if (tt != tc) {
      cout << "\n";
    }
  }
  return 0;
}
