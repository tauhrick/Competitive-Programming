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
  int n, a, b, c;
  string s;
  cin >> n >> a >> b >> c >> s;
  vector<char> moves(n, '#');
  for (int i = 0; i < (int) s.size(); ++i) {
    auto ch = s[i];
    if (ch == 'R') {
      if (b > 0) {
        moves[i] = 'P';
        --b;
      }
    } else if (ch == 'P') {
      if (c > 0) {
        moves[i] = 'S';
        --c;
      }
    } else {
      if (a > 0) {
        moves[i] = 'R';
        --a;
      }
    }
  }
  int wins = 0;
  for (int i = 0; i < n; ++i) {
    if (moves[i] == '#') {
      if (a > 0) {
        moves[i] = 'R';
        --a;
      } else if (b > 0) {
        moves[i] = 'P';
        --b;
      } else {
        moves[i] = 'S';
        --c;
      }
    } else {
      ++wins;
    }
  }
  if (2 * wins >= n) {
    cout << "YES\n";
    for (auto ch : moves) {
      cout << ch;
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
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
