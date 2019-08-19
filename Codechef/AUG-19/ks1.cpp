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
  vector<int> A(n + 1);
  map<int, vector<int>> pos;
  int xor_sum = 0;
  pos[0].emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    xor_sum ^= A[i];
    pos[xor_sum].emplace_back(i);
  }
  long long prs = 0;
  for (auto& info : pos) {
    long long tot = accumulate(info.second.begin(), info.second.end(), 0LL);
    int cnt = info.second.size();
    for (int i = 0, nxt = cnt - 1; i < cnt; ++i, --nxt) {
      tot -= info.second[i];
      prs += tot - 1LL * nxt * info.second[i];
      prs -= nxt;
    }
  }
  cout << prs << "\n";
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
