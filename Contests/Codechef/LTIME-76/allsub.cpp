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
  string s, r;
  cin >> s >> r;
  map<char, int> cnt_s, cnt_r;
  for (auto ch : s) {
    ++cnt_s[ch];
  }
  for (auto ch : r) {
    ++cnt_r[ch];
  }
  for (auto i : cnt_s) {
    if (cnt_r[i.first] < i.second) {
      cout << "Impossible\n";
      return;
    }
    cnt_r[i.first] -= i.second;
  }
  char mx = *max_element(s.begin(), s.end());
  string pref, suff;
  for (auto i : cnt_r) {
    if (i.first > s.front()) {
      for (int j = 0; j < i.second; ++j) {
        suff += i.first;
      }
    } else if (i.first < s.front()) {
      for (int j = 0; j < i.second; ++j) {
        pref += i.first;
      }
    } else {
      string to_add;
      for (int j = 0; j < i.second; ++j) {
        to_add += i.first;
      }
      if (to_add + s < s + to_add) {
        pref += to_add;
      } else {
        suff += to_add;
      }
    }
  }
  cout << pref << s << suff << "\n";
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
