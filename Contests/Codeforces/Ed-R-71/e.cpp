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

const int MASK_1 = 0b11111110000000;
const int MASK_2 = 0b00000001111111;

int query(vector<int>& q) {
  cout << "? ";
  for (auto i : q) {
    cout << i << " ";
  }
  cout << endl;
  int resp;
  cin >> resp;
  if (resp == -1) {
    exit(0);
  }
  return resp;
}

void test_case() {
  int res = 0;
  {
    vector<int> q;
    for (int i = 0; i < 100; ++i) {
      q.emplace_back(MASK_1 | i);
    }
    int resp = query(q);
    for (int bit = 7; bit < 14; ++bit) {
      if (resp & (1 << bit)) {
      } else {
        res |= (1 << bit);
      }
    }
  }
  {
    vector<int> q;
    for (int i = 0; i < 100; ++i) {
      q.emplace_back((i << 7) | MASK_2);
    }
    int resp = query(q);
    for (int bit = 0; bit < 7; ++bit) {
      if (resp & (1 << bit)) {
      } else {
        res |= (1 << bit);
      }
    }
  }
  cout << "! " << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
