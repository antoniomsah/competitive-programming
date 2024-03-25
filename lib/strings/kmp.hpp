// Knuth-Morris-Pratt algorithm

template <typename T>
vector<int> kmp(int sz, const T s[]) {
	vector<int> p(sz);
	for (int i = 1; i < sz; i++) {
		int &j = p[i];
		for (int j = p[i-1]; j > 0 and s[i] != s[j]; j = p[j-1]);
		if (s[i] == s[j]) j++;
	}
	return p;
}
