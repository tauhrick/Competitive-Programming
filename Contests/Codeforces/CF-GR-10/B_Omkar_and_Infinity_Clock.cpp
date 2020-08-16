#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/mnt/d/Programming/CP/Library/Debug/Debug.cpp"
#else
#define debug(...) 42
#endif

void RunTestCase() {
  int n;
  int64_t k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int min_a = *min_element(a.begin(), a.end());
  int max_a = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (k & 1) {
      a[i] = max_a - a[i];
    } else {
      a[i] = a[i] - min_a;
    }
    cout << a[i] << " ";
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