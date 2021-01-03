#include <bits/stdc++.h>

#ifdef LOCAL
#include "../testlib/testlib.h"
#else
#include "testlib.h"
#endif

using namespace std;

int main(int argc, char * argv[]) {
  registerValidation(argc, argv);

  const int kLimN_Q = int(1e5);
  int n = inf.readInt(1, kLimN_Q, "n");
  inf.readSpace();
  int q = inf.readInt(1, kLimN_Q, "q");
  inf.readEoln();

  const int kLimA_i = int(1e7);
  for (int i = 1; i <= n; ++i) {
    inf.readInt(1, kLimA_i, "A_i");
    if (i == n) {
      inf.readEoln();
    } else {
      inf.readSpace();
    }
  }

  for (int i = 1; i <= q; ++i) {
    int l = inf.readInt(1, n, "l_i");
    inf.readSpace();
    int r = inf.readInt(1, n, "r_i");
    inf.readEoln();
    ensuref(l != r, "l_i can't be equal to r_i.");
  }

  inf.readEof();
  
  return 0;
}