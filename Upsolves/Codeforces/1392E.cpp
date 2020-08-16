#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/mnt/d/Programming/CP/Library/Debug/Debug.cpp"
#else
#define debug(...) 42
#endif

void RunTestCase() {
  int n;
  cin >> n;
  auto grid = vector(n, vector(n, int64_t{0}));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i & 1) {
        grid[i][j] = 1LL << (i + j);
      }
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  int queries;
  cin >> queries;
  while (queries--) {
    int64_t k;
    cin >> k;
    int r = 0, c = 0;
    int64_t sum = 0;
    while (true) {
      cout << r + 1 << " " << c + 1 << endl;
      sum += grid[r][c];
      if (r == n - 1 && c == n - 1) {
        break;
      } else if (r == n - 1) {
        ++c;
      } else if (c == n - 1) {
        ++r;
      } else {
        int bit = (k >> (r + c + 1)) & 1;
        if (r & 1) {
          if (bit) {
            ++c;
          } else {
            ++r;
          }
        } else {
          if (bit) {
            ++r;
          } else {
            ++c;
          }
        }
      }
    }
    assert(sum == k);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  RunTestCase();
  return 0;
}