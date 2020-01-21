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

map<char, string> val = {
  {'A', ".-"},
  {'B', "-..."},
  {'C', "-.-."},
  {'D', "-.."},
  {'E', "."},
  {'F', "..-."},
  {'G', "--."},
  {'H', "...."},
  {'I', ".."},
  {'J', ".---"},
  {'K', "-.-"},
  {'L', ".-.."},
  {'M', "--"},
  {'N', "-."},
  {'O', "---"},
  {'P', ".--."},
  {'Q', "--.-"},
  {'R', ".-."},
  {'S', "..."},
  {'T', "-"}, 
  {'U', "..-"},
  {'V', "...-"},
  {'W', ".--"},
  {'X', "-..-"}, 
  {'Y', "-.--"},
  {'Z', "--.."}
};

void test_case() {
  string seq;
  int n;
  cin >> seq >> n;
  map<string, int> st;
  while (n--) {
    string s;
    cin >> s;
    string code;
    for (auto ch : s) {
      code += val[ch];
    }
    ++st[code];
  }
  vector<long long> dp(seq.size(), -1);
  function<long long(int)> solve = [&](int ind) {
    if (ind > (int) seq.size()) {
      return 0LL;
    } else if (ind == (int) seq.size()) {
      return 1LL;
    }
    auto& ans = dp[ind];
    if (ans == -1) {
      ans = 0;
      for (auto s : st) {
        if (seq.substr(ind, s.first.size()) == s.first) {
          ans += s.second * solve(ind + s.first.size());
        }
      }
    }
    return ans;
  };
  cout << solve(0) << "\n";
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
