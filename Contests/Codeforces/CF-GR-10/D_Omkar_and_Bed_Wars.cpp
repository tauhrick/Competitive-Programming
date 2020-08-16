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
  string s;
  cin >> s;
  int moves = 0;
  int rotate_index = 0;
  while (rotate_index < n && s[rotate_index] == s[n - 1]) {
    ++rotate_index;
  }
  if (rotate_index == n) {
    cout << (n + 2) / 3 << "\n";
    return;
  }
  rotate(s.begin(), s.begin() + rotate_index, s.end());
  for (int i = 0; i < n; ) {
    int st = i;
    while (i < n && s[i] == s[st]) {
      ++i;
    }
    moves += (i - st) / 3;
  }
  cout << moves << "\n";
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