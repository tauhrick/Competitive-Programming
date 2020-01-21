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
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> A(n + 1);
  set<int> rem_inds;
  for (int i = 1; i <= n; ++i) {
    rem_inds.insert(i);
  }
  set<pair<int, int>> updates;
  map<int, pair<int, int>> prv;
  bool bad = false;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    if (prv.count(z)) {
      bad = prv[z] != make_pair(x, y);
    }
    prv[z] = make_pair(x, y);
    A[z] = x;
    rem_inds.erase(z);
    updates.insert({z, y - 1});
  }
  if (bad) {
    cout << "No\n";
    return;
  } 
  vector<int> last_updt(k + 1, 0);
  vector<int> cnt_behind(k + 1, 0);
  while (!updates.empty()) {
    auto p = *updates.begin();
    int z = p.first;
    int rem = p.second;
    updates.erase(updates.begin());
    int lo = last_updt[A[z]];
    int prv_cnt = cnt_behind[A[z]] + (lo > 0);
    int tot_req = rem;
    rem -= prv_cnt;
    if (rem < 0) {
      cout << "No\n";
      return;
    }      
    while (rem--) {
      if (rem_inds.empty()) {
        cout << "No\n";
        return;
      }
      auto ind = *rem_inds.upper_bound(lo);
      rem_inds.erase(ind);
      if (ind < z) {
        A[ind] = A[z];
      } else {
        cout << "No\n";
        return;
      }
    }
    last_updt[A[z]] = z;
    cnt_behind[A[z]] = tot_req;
  }
  int put = k;
  set<int> done;
  for (int i = n; i >= 1; --i) {
    if (A[i] == 0) {
      while (done.count(put)) {
        if (put == 1) {
          cout << "No\n";
          return;
        }
        --put;
      }
      A[i] = put;
    } else {
      done.insert(A[i]);
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; ++i) {
    cout << A[i] << " \n"[i == n];
  }
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
