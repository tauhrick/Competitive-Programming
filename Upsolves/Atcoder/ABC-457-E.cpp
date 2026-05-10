#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "/Users/mac-mini/Desktop/CP/Library/Debug.hpp"
#endif

const int kInf = 3e5;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n, m;
  vector<pair<int, int>> clothes;
  int q;
  vector<pair<int, int>> queries;

  void Read() {
    cin >> n >> m;
    clothes.resize(m);
    for (auto& i : clothes) {
      cin >> i.first >> i.second;
    }
    cin >> q;
    queries.resize(q);
    for (auto& query : queries) {
      cin >> query.first >> query.second;
    }
  }

  void Solve() {
    vector<vector<int>> left_ends(n + 1);
    vector<vector<int>> right_ends(n + 1);
    for (auto& cloth : clothes) {
      left_ends[cloth.second].push_back(cloth.first);
      right_ends[cloth.first].push_back(cloth.second);
    }
    for (int i = 1; i <= n; i++) {
      sort(left_ends[i].begin(), left_ends[i].end());
      sort(right_ends[i].begin(), right_ends[i].end());
    }
    // Store the min right end for something that starts >= i.
    vector<int> min_right_end(n + 1, kInf);
    for (int i = n; i >= 1; i--) {
      if (i + 1 <= n) {
        min_right_end[i] = min_right_end[i + 1];
      }
      if (!right_ends[i].empty()) {
        min_right_end[i] = min(min_right_end[i], right_ends[i][0]);
      }
    }
    for (auto& query : queries) {
      auto [l, r] = query;
      // Find the last valid right starting at l.
      int en = upper_bound(right_ends[l].begin(), right_ends[l].end(), r) -
               right_ends[l].begin() - 1;
      // Find the first valid left ending at r.
      int st = lower_bound(left_ends[r].begin(), left_ends[r].end(), l) -
               left_ends[r].begin();
      if (0 <= en && en < right_ends[l].size() && 0 <= st &&
          st < left_ends[r].size()) {
        // Handle the edge case rightly when there could be a single cloth
        // covering [l, r]. It's not necessary for any of the endpoints of the
        // second cloth to be touching the endpoints in this scenario.
        if (right_ends[l][en] == r && left_ends[r][st] == l) {
          if (st + 1 < left_ends[r].size() || en - 1 >= 0) {
            cout << "Yes";
          } else if (min_right_end[l] < r ||
                     (l + 1 <= n && min_right_end[l + 1] <= r)) {
            cout << "Yes";
          } else {
            cout << "No";
          }
        } else if (right_ends[l][en] >= left_ends[r][st] - 1) {
          cout << "Yes";
        } else {
          cout << "No";
        }
      } else {
        cout << "No";
      }
      cout << '\n';
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
