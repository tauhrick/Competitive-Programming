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
  cin >> s;
  if (s.find(".") == string::npos) {
    s = s + ".";
  }
  int b = 0;
  int dec = s.find(".");
  int non_zero = -1;
  for (int i = 0; i < (int) s.size(); ++i) {
    if (i == dec || s[i] == '0') {
      continue;
    } else {
      non_zero = i;
      break;
    }
  }
  if (non_zero == -1) {
    assert(false);
  }
  if (non_zero < dec) {
    b = dec - (non_zero + 1);
  } else {
    b = -(non_zero - dec);
  }
  while (s.back() == '0' || s.back() == '.') {
    s.pop_back();
  }
  string a;
  for (int i = non_zero; i < (int) s.size(); ++i) {
    if (s[i] == '.') {
      continue;
    } else {
      a += s[i];
    }
  }
  if (a.size() == 1) {
    cout << a;
  } else {
    cout << a.front() << "." << a.substr(1);
  }
  if (b != 0) {
    cout << "E" << b;
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
