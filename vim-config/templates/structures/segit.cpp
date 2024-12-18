template <typename ND, typename T = typename ND::T>
struct segment_tree {
	int n;
	vector<ND> seg;

	segtree(int n) : n(n), seg(2*n) {}

	segtree(vector<T> &v) : n(v.size()), seg(2*n) { 
		for (int i = 0; i < n; i++) {
			seg[i+n] = ND(v[i]);
		}
		for (int i = n-1; i; i--) { // Build.
			seg[i] = seg[2*i] + seg[2*i+1];
		}
	}

	void update(int pos, T val) { 
		int p = pos+n;
		seg[p] = ND(val);
		while (p /= 2) {
			seg[p] = seg[2*p] + seg[2*p+1];
		}
	}

	ND query(int l, int r) { 
		ND tl, tr;
		r++; // For inclusive queries.
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) tl = tl + seg[l++];
			if (r&1) tr = tr + seg[--r];
		}
		return tl + tr;
	}
};

struct node {
	using T = ll;
	T x;
	node() : x(0) {}
	node(T _x) : x(_x) {}
	friend node operator+(node a, node b) {
		return node(a.x+b.x);
	}
};

