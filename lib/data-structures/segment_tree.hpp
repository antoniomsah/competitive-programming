// Segment tree

template <class T>
struct segment_tree {
	const T NEUT = T();

	int n;
	vector<T> seg;
 
	// O(n)
	T build(int p, int l, int r, vector<T> &v) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p,l,m,v)+build(2*p+1,m+1,r,v);
	}
 
	segment_tree(vector<T> &v) : n(v.size()), seg(4*n) { 
		build(1,0,n-1,v); 
	}

	segment_tree(int n) : n(n), seg(4*n) {}
 
	// O(lgn)
	T update(int a, T x, int p, int l, int r) {
		if (a < l or r < a) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(a,x,2*p,l,m)+update(a,x,2*p+1,m+1,r);
	}
 
	// O(lgn)
	T query(int a, int b, int p, int l, int r) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return NEUT;
		int m = (l+r)/2;
		return query(a,b,2*p,l,m)+query(a,b,2*p+1,m+1,r);
	}
 
	void update(int p, T x) { update(p,x,1,0,n-1); }
	T query(int l, int r) { return query(l,r,1,0,n-1); }
};
