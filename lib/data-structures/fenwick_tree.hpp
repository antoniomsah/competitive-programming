template <class T>
struct fenwick_tree {
	static constexpr T NEUT = T();

	int n;
	vector<T> bit;

	fenwick_tree(int n) : n(n), bit(n) {}

	// linear construction
	fenwick_tree(const vector<T>& a) {
		for (int i = 0; i < n; i++) {
			bit[i] += a[i];
			int j = i|(i+1);
			if (j < n) bit[j] += bit[i];
		}
	}

	void update(int pos, T dif)  {
		for (; pos < n; pos |= pos + 1) bit[pos] += dif;
	}

	T query(int pos) { 
		T res = NEUT;
		for (; pos > 0; pos &= pos - 1) res += bit[pos-1];
		return res;
	}

	// type T must have operator < and <=
	int lower_bound(T sum) { // min pos st sum of [0, pos] >= sum
		if (sum <= NEUT()) return -1;
		int pos = 0;
		for (int pw = (1 << 25); pw; pw >>= 1) {
			if (pos+pw <= n && bit[pos+pw-1] < sum)
				pos += pw, sum -= bit[pos-1];
		}
		return pos;
	}
};
