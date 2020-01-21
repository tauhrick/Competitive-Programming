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
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  map<int, vector<int>> positions;
  for (int i = 0; i < m; ++i) {
    cin >> x[i];
    positions[x[i]].emplace_back(i);
  }
  long long ans = 0;
  for (int i = 0; i + 1 < m; ++i) {
    ans += abs(x[i + 1] - x[i]);
  }
  cout << ans << "\n";
  vector<int> pos(n + 1);
  iota(pos.begin(), pos.end(), 0);
  for (int i = 2; i <= n; ++i) {
    auto sub = [&](int p, int i, int d) {
      p += d;
      if (p >= 0 && p < m) {
        ans -= abs(pos[i] - pos[x[p]]);
      }
    };
    auto add = [&](int p, int i, int d) {
      p += d;
      if (p >= 0 && p < m) {
        ans += abs(pos[i] - pos[x[p]]);
      }
    };
    auto sub_common = [&](int p, int i, int d) {
      p += d;
      if (p >= 0 && p < m) {
        if (x[p] == i + 1) {
          ans -= abs(pos[i] - pos[x[p]]);
        }
      }
    };
    auto add_common = [&](int p, int i, int d) {
      p += d;
      if (p >= 0 && p < m) {
        if (x[p] == i + 1) {
          ans += abs(pos[i] - pos[x[p]]);
        }
      }
    };
    for (auto j : positions[i - 1]) {
      sub(j, i - 1, -1);
      sub(j, i - 1, 1);
    }
    for (auto j : positions[i]) {
      sub(j, i, -1);
      sub(j, i, 1);
    }
    for (auto j : positions[i - 1]) {
      add_common(j, i - 1, -1);
      add_common(j, i - 1, 1);
    }
    swap(pos[i], pos[i - 1]);
    for (auto j : positions[i - 1]) {
      add(j, i - 1, -1);
      add(j, i - 1, 1);
    }
    for (auto j : positions[i]) {
      add(j, i, -1);
      add(j, i, 1);
    }
    for (auto j : positions[i - 1]) {
      sub_common(j, i - 1, -1);
      sub_common(j, i - 1, 1);
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
