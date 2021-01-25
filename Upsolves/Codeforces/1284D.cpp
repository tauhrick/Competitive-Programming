#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

struct Interval {
  int st, en, ind;
};

struct Event {
  int time, ind, typ;

  bool operator<(const Event &other) const {
    return make_pair(time, typ) < make_pair(other.time, other.typ);
  }
};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<Interval> a, b;

  void Read() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].st >> a[i].en >> b[i].st >> b[i].en;
      a[i].ind = b[i].ind = i;
    }
  }
 
  void Solve() {
    cout << (Bad(a, b) || Bad(b, a) ? "NO" : "YES") << "\n";
  }

  bool Bad(vector<Interval> &overlap, vector<Interval> &non_overlap) {
    vector<Event> operations;
    for (auto &interval : overlap) {
      operations.push_back({interval.st, interval.ind, 1});
      operations.push_back({interval.en + 1, interval.ind, -1});
    }
    sort(operations.begin(), operations.end());
    multiset<int> st, en;
    for (int i = 0, j = 0; i < int(operations.size()); i = j) {
      while (j < int(operations.size()) && operations[j].time == operations[i].time) {
        int new_st = non_overlap[operations[j].ind].st;
        int new_en = non_overlap[operations[j].ind].en;
        if (operations[j].typ == 1) {
          st.insert(new_st);
          en.insert(new_en);
          if (*st.rbegin() > *en.begin()) return true;
        } else {
          st.erase(st.find(new_st));
          en.erase(en.find(new_en));
        }
        ++j;
      }
    }
    return false;
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}