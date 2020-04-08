#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(vector<int>& v) {
    int n = v.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && v[i] != v[j]) {
            j = pi[j - 1];
        }
        if (v[i] == v[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> find_occurrence(vector<int>& text, vector<int>& pattern) {
    vector<int> curr = pattern;
    curr.emplace_back(INT_MIN);
    for (auto& i : text) {
        curr.emplace_back(i);
    }
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = prefix_function(curr);
    for (int i = sz2 + 1; i <= sz1 + sz2; ++i) {
        if (lps[i] == sz2) {
            v.emplace_back(i - 2 * sz2);
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> A(n);
    vector<int> diff_A = {INT_MAX};
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (i != 0) {
            diff_A.emplace_back(A[i] - A[i - 1]);
            diff_A.emplace_back(INT_MAX);
        }
    }
    vector<int> B(w);
    vector<int> diff_B = {INT_MAX};
    for (int i = 0; i < w; ++i) {
        cin >> B[i];
        if (i != 0) {
            diff_B.emplace_back(B[i] - B[i - 1]);
            diff_B.emplace_back(INT_MAX);
        }
    }
    vector<int> pos = find_occurrence(diff_A, diff_B);
    cout << pos.size() << "\n";
    return 0;
}

