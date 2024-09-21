#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "/Users/mac-mini/Desktop/CP/Library/Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n;

  void Read() { cin >> n; }

  void Solve() {
    string s = "";

    // Try to form the string and find the longest suffix that we can find.
    while (int(s.size()) < n) {
      if (IsSubstring(s + "0")) {
        s += "0";
      } else if (IsSubstring(s + "1")) {
        s += "1";
      } else {
        break;
      }
    }

    // There can be a scenario when the string is not formed yet. We just need
    // to form the string by adding letters to the beginning of it.
    while (int(s.size()) < n) {
      if (IsSubstring("0" + s)) {
        s = "0" + s;
      } else {
        s = "1" + s;
      }
    }

    cout << "! " << s << endl;
  }

  bool IsSubstring(string s) {
    int response;
    cout << "? " << s << endl;
    cin >> response;
    assert(response != -1);
    return response == 1;
  }
};

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
