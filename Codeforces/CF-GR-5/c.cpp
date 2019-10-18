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
  vector<pair<tuple<int, int, int>, int>> pts(n);
  for (int i = 0; i < n; ++i) {
    pts[i].second = i + 1;
    auto& [x, y, z] = pts[i].first;
    cin >> x >> y >> z;
  }
  sort(pts.begin(), pts.end());
  vector<pair<int, int>> order;
  vector<pair<tuple<int, int, int>, int>> xy;
  for (int i = 0; i < n; ) {
    auto& [x1, y1, z1] = pts[i].first;
    if (i + 1 < n) {
      auto& [x2, y2, z2] = pts[i + 1].first;
      if (x1 == x2 && y1 == y2) {
        order.emplace_back(pts[i].second, pts[i + 1].second);
        i += 2;
        continue;
      }
    }
    xy.push_back(pts[i++]);
  }
  debug(order);
  vector<pair<tuple<int, int, int>, int>> x;
  for (int i = 0; i < (int) xy.size(); ) {
     auto& [x1, y1, z1] = xy[i].first;
     if (i + 1 < (int) xy.size()) {
       auto& [x2, y2, z2] = xy[i + 1].first;
       if (x1 == x2) {
         order.emplace_back(xy[i].second, xy[i + 1].second);
         i += 2;
         continue;
       }
     }
     x.push_back(xy[i++]);
  }
  debug(order);
  for (int i = 0; i < (int) x.size(); ) {
    order.emplace_back(x[i].second, x[i + 1].second);
    i += 2;
  }
  debug(order);
  assert((int) order.size() == n / 2);
  for (int i = 0; i < (int) order.size(); ++i) {
    cout << order[i].first << " " << order[i].second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
