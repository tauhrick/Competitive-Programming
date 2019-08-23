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
  string s;
  int a, b;
  cin >> s >> a >> b;
  int l = s.size();
  vector<int> power(l);
  power[0] = 1 % b;
  for (int i = 1; i < l; ++i) {
    power[i] = (power[i - 1] * 10) % b;
  }
  int en = 0;
  for (int i = l - 1, p = 0; i >= 0; --i, ++p) {
    en += ((s[i] - '0') * power[p]) % b;
    en %= b;
  }
  int st = 0;
  for (int i = 0, p = l - 1; i < l; ++i, --p) {
    st = (st * 10 + (s[i] - '0')) % a;
    en -= ((s[i] - '0') * power[p]) % b;
    en %= b;
    en += b;
    en %= b;
    if (st == 0 && en == 0 && i + 1 < l && s[i + 1] != '0') {
      cout << "YES\n" << s.substr(0, i + 1) << "\n" << s.substr(i + 1) << "\n";
      return;
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
