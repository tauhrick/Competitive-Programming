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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <typename T>
using HashTable = gp_hash_table<long long, T, custom_hash>;

const int N = 1e5 + 10;

int n, m;
int A[N];
int BLOCK_SZ;
vector<int> query_ans;
HashTable<int> cnt;
int curr = 0;

struct Query {
  int l, r, idx;

  bool operator <(Query& o) const {
    return make_pair(l / BLOCK_SZ, r) < make_pair(o.l / BLOCK_SZ, o.r);
  }
};

void add(int pos) {
  if (pos >= 1 && pos <= n) {
    if (cnt[A[pos]] == A[pos]) {
      --curr;
    }
    ++cnt[A[pos]];
    if (cnt[A[pos]] == A[pos]) {
      ++curr;
    }
  }
}

void remove(int pos) {
  if (pos >= 1 && pos <= n) {
    if (cnt[A[pos]] == A[pos]) {
      --curr;
    }
    --cnt[A[pos]];
    if (cnt[A[pos]] == A[pos]) {
      ++curr;
    }
  }
}

int solve_query(Query& q) {
  return curr;
}

void mo_s_algo(vector<Query>& queries) {
  sort(queries.begin(), queries.end());
  int curr_l = -1, curr_r = -1;
  for (auto& q: queries) {
    while (curr_l > q.l) {
      add(--curr_l);
    }
    while (curr_r < q.r) {
      add(++curr_r);
    }
    while (curr_l < q.l) {
      remove(curr_l++);
    }
    while (curr_r > q.r) {
      remove(curr_r--);
    }
    query_ans[q.idx] = solve_query(q);
    debug(q.idx, cnt);
  }
}

void test_case() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  BLOCK_SZ = sqrt(n);
  vector<Query> queries(m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r, i};
  }
  query_ans.resize(m);
  mo_s_algo(queries);
  for (auto ans : query_ans) {
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
