#include <bits/stdc++.h>

#ifdef LOCAL
#include "../testlib/testlib.h"
#else
#include "testlib.h"
#endif

using namespace std;

int main(int argc, char * argv[]) {
  registerGen(argc, argv, 1);

  const int kLimN_Q = int(1e5);
  int n = rnd.next(1, kLimN_Q);
  int q = rnd.next(1, kLimN_Q);
  cout << n << " " << q << "\n";

  const int kLimA_i = int(1e7);
  vector<int> a;
  set<int> done;
  for (int i = 1; i <= n; ++i) {
    int x;
    if (rnd.next(1, 5) == 1 && !a.empty()) {
      x = a[rnd.next(0, int(a.size()) - 1)];
    } else {
      x = rnd.next(1, kLimA_i);
      if (!done.count(x)) {
        done.insert(x);
        a.emplace_back(x);
      }
    }
    cout << x << (i == n ? '\n' : ' ');
  }

  for (int i = 1; i <= q; ++i) {
    int l = rnd.next(1, n);
    int r = l;
    while (r == l) {
      r = rnd.next(1, n);
    }
    cout << l << " " << r << "\n";
  }

  return 0;
}
