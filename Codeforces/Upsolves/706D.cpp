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

const int B = 30;

struct Node {
  Node* l;
  Node* r;
  int cnt;
  
  Node(Node* _l = nullptr, Node* _r = nullptr, int _cnt = 0) {
    l = _l;
    r = _r;
    cnt = _cnt;
  }
};

Node* head = new Node();

void insert_trie(int x) {
  Node* curr = head;
  for (int bit = B; bit >= 0; --bit) {
    if (x & (1 << bit)) {
      if ((curr -> r) == nullptr) {
        (curr -> r) = new Node();
      }
      curr = (curr -> r);
    } else {
      if ((curr -> l) == nullptr) {
        (curr -> l) = new Node();
      }
      curr = (curr -> l);
    }
    (curr -> cnt) = (curr -> cnt) + 1;
  }
}

void erase_trie(int x) {
  Node *curr = head;
  for (int bit = B; bit >= 0; --bit) {
    if (x & (1 << bit)) {
      Node* buff = (curr -> r);
      (buff -> cnt) = (buff -> cnt) - 1;
      if ((buff -> cnt) == 0) {
        (curr -> r) = nullptr;
        break;
      }
      curr = buff;
    } else {
      Node* buff = (curr -> l);
      (buff -> cnt) = (buff -> cnt) - 1;
      if ((buff -> cnt) == 0) {
        (curr -> l) = nullptr;
        break;
      }
      curr = buff;
    }
  }
}

int cal_max(int x) {
  int ret = 0;
  Node *curr = head;
  for (int bit = B; bit >= 0; --bit) {
    if (x & (1 << bit)) {
      if ((curr -> l) != nullptr) {
        curr = (curr -> l);
        ret += (1 << bit);
      } else {
        curr = (curr -> r);
      }
    } else {
      if ((curr -> r) != nullptr) {
        curr = (curr -> r);
        ret += (1 << bit);
      } else {
        curr = (curr -> l);
      }
    }
  }
  return ret;
}

void test_case() {
  int q;
  cin >> q;
  insert_trie(0);
  while (q--) {
    char typ;
    int x;
    cin >> typ >> x;
    if (typ == '+') {
      insert_trie(x);
    } else if (typ == '-') {
      erase_trie(x);
    } else {
      cout << cal_max(x) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
