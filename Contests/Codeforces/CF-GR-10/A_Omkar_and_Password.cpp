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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[0] == a[n - 1]) {
    cout << n;
  } else {
    cout << 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    RunTestCase();
  }
  return 0;
}