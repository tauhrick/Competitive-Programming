vector < int > prefixFunction(string &s) {
	int n = s.size();
	vector < int > pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pi[i] = j;
	}
	return pi;
}

vector < int > findOccurrences(string &text, string &pattern) {
	string curr = pattern + '#' + text;
	int sz1 = text.size(), sz2 = pattern.size();
	vector < int > v;
	vector < int > lps = prefixFunction(curr);
	for (int i = sz2 + 1; i <= sz1 + sz2; ++i) {
		if (lps[i] == sz2) {
			v.emplace_back(i - 2 * sz2);
		}
	}
	return v;
}