vector<int> prefixFunction(vector<int> &v) {
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

vector<int> findOccurrences(vector<int> &text, vector<int> &pattern) {
	vector<int> curr = pattern;
	curr.emplace_back(-1);
	for (auto &i : text) {
		curr.emplace_back(i);
	}
	int sz1 = text.size(), sz2 = pattern.size();
	vector<int> v;
	vector<int> lps = prefixFunction(curr);
	for (int i = sz2 + 1; i <= sz1 + sz2; ++i) {
		if (lps[i] == sz2) {
			v.emplace_back(i - 2 * sz2);
		}
	}
	return v;
}