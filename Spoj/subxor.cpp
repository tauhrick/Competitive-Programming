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

class Trie {
  const static int SZ = 2; //
  const static int B = '0'; //
  
public:
  struct Node {
    Node* nxt[SZ];
    int cnt_pass;
    int cnt_last;
    
    Node(int _cnt_pass = 0, int _cnt_last = 0) {
      cnt_pass = _cnt_pass;
      cnt_last = _cnt_last;
      for (int i = 0; i < SZ; ++i) {
        nxt[i] = nullptr;
      }
    }
  };
  
  Node* head = new Node();
  
  void insert(string& s) {
    Node* node = head;
    for (int i = 0; i < (int) s.size(); ++i) {
      auto& curr = *node;
      int e = s[i] - B;
      if (curr.nxt[e] == nullptr) {
        curr.nxt[e] = new Node();
      }
      node = curr.nxt[e];
      ++(*node).cnt_pass;
    }
    ++(*node).cnt_last;
  }
  
  void erase(string& s) {
    Node* node = head;
    for (int i = 0; i < (int) s.size(); ++i) {
      auto& curr = *node;
      int e = s[i] - B;
      assert(curr.nxt[e] != nullptr);
      if (((curr.nxt[e]) -> cnt_pass) == 1) {
        curr.nxt[e] = nullptr;
        return;
      }
      node = curr.nxt[e];
      --(*node).cnt_pass;
    }
    --(*node).cnt_last;
  }
  
  int get(string& s, int k) { //
    Node* node = head;
    int ans = 0;
    for (int i = 0, p = 30; i < (int) s.size(); ++i, --p) {
      auto& curr = *node;
      int s_bit = s[i] - B;
      int k_bit = (k & (1 << p)) != 0;
      int e = s_bit ^ k_bit;
      if (k_bit == 1 && curr.nxt[e ^ 1] != nullptr) {
        ans += (curr.nxt[e ^ 1]) -> cnt_pass;
      }
      if (curr.nxt[e] == nullptr) {
        break;
      }
      node = curr.nxt[e];
    }
    return ans;
  }
};

const int N = 1e5 + 10;

int n, k;
int A[N];

string get_bin(int x) {
  string ret;
  while (x != 0) {
    if (x & 1) {
      ret += '1';
    } else {
      ret += '0';
    }
    x >>= 1;
  }
  while ((int) ret.size() < 31) {
    ret += '0';
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

void test_case() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  Trie t;
  string s = get_bin(0);
  t.insert(s);
  int pref_xor = 0;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    pref_xor ^= A[i];
    string s = get_bin(pref_xor);
    res += t.get(s, k);
    t.insert(s);
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    test_case();
  }
  return 0;
}
