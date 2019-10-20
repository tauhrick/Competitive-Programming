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
  string s, t;
  cin >> s >> t;
  if (s.find(t) != string::npos) {
    cout << s.size() << "\n";
  } else if (t.find(s) != string::npos) {
    cout << t.size() << "\n";
  } else {
    int ans = s.size() + t.size();
    { // s + t
      int ded = 0;
      for (int i_s = s.size() - 1, i_t = 0; i_s >= 0 && i_t < t.size(); --i_s, ++i_t) {
        if (s[i_s] != t[i_t]) {
          break;
        }
        ++ded;
      }
      int curr = s.size() + t.size() - ded;
      ans = min(ans, curr);
    }
    { // t + s
      int ded = 0;
      for (int i_s = 0, i_t = t.size() - 1; i_s <= 0 && i_t >= 0; ++i_s, --i_t) {
        if (s[i_s] != t[i_t]) {
          break;
        }
        ++ded;
      }
      int curr = s.size() + t.size() - ded;
      ans = min(ans, curr);
    }
    cout << ans << "\n";
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
