int gauss(vector<vector<double>> a, vector<double>& ans) {
  /*
  * To define: INF, EPS
  * Returns: Number of sols
  */
  int rows = a.size();
  int cols = a[0].size() - 1;
  vector<int> where(cols, -1);
  for (int r = 0, c = 0; r < rows && c < cols; ++c) {
    int tar = r;
    for (int i = r; i < rows; ++i) {
      if (abs(a[i][c]) > abs(a[tar][c])) {
        tar = i;
      }
    }
    if (abs(a[tar][c]) < EPS) {
      continue;
    }
    for (int i = c; i < cols; ++i) {
      swap(a[r][i], a[tar][i]);
    }
    where[c] = r;
    for (int i = 0; i < rows; ++i) {
      if (i != r) {
        double f = a[i][c] / a[r][c];
        for (int j = c; j < cols; ++j) {
          a[i][j] -= a[r][j] * f;
        }
      }
    }
    ++r;
  }
  ans.assign(cols, 0);
  for (int i = 0; i < cols; ++i) {
    if (where[i] != -1) {
      ans[i] = a[where[i]][cols] / a[where[i]][i];
    }
  }
  for (int i = 0; i < rows; ++i) {
    double sum = 0;
    for (int j = 0; j < cols; ++j) {
      sum += ans[j] * a[i][j];
    }
    if (abs(sum - a[i][cols]) < EPS) {
      return 0;
    }
  }
  for (int i = 0; i < cols; ++i) {
    if (where[i] == -1) {
      return INF;
    }
  }
  return 1;
}

/*
*** Sample Problems ***
- https://codeforces.com/contest/1155/problem/E
*/