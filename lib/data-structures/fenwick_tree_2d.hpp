// Fenwick Tree 2D

template <class T> 
struct fenwick_tree_2d {
	int n, m;
	vector<T> bit;
	fenwick_tree_2d(int _n, int _m) : n(_n), m(_m), bit(n*m) {}

	// returns sum[0..x][0..y]
	T query(int x, int y) {
		T res = 0;
		for (x += 1; x; x -= x&-x)
			for (int z = y+1; z; z -= z&-z)
				res += bit[(x-1)*m+z-1];
		return res;
	}

	// x1 <= x2 and y1 <= y2
	// returns sum[x1..x2][y1..y2]
	T query(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
	}

	void update(int x, int y, T val) {
		for (x += 1; x <= n; x += x&-x) 
			for (int z = y+1; z <= m; z += z&-z) 
				bit[(x-1)*m+z-1] += val;
	}
};
