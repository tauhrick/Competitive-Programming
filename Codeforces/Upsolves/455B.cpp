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
  const static int SZ = 26; //
  const static int B = 'a'; //
  
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
  
  pair<bool, bool> dfs(Node* curr) {
    bool is_any = false;
    bool win = false;
    bool lose = false;
    for (int i = 0; i < SZ; ++i) {
      if ((curr -> nxt[i]) != nullptr) {
        auto res = dfs(curr -> nxt[i]);
        debug(i, res);
        is_any = true;
        win |= !res.first;
        lose |= !res.second;
      }
    }
    if (!is_any) {
      return make_pair(false, true);
    } else {
      return make_pair(win, lose);
    }
  }
};

void test_case() {
  int n, k;
  cin >> n >> k;
  Trie tree;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    tree.insert(s);
  }
  auto res = tree.dfs(tree.head);
  debug(res);
  if (res.first && res.second) {
    cout << "First";
  } else if (res.first) {
    cout << (k & 1 ? "First" : "Second");
  } else {
    cout << "Second";
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
