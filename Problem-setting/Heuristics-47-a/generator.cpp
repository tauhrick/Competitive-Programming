#include <bits/stdc++.h>

#ifdef LOCAL
#include "../testlib/testlib.h"
#else
#include "testlib.h"
#endif

using namespace std;

int main(int argc, char * argv[]) {
  registerGen(argc, argv, 1);

  cout << rnd.next(-100, 100) << "\n";

  return 0;
}
