template <typename ND, typename T = typename ND::T>
struct segment_tree {
	int n;
	vector<ND> seg;

	T build(int p, int l, int r, vector<T> &v) {
		if (l == r) return seg[p] = ND(v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p,l,m,v)+build(2*p+1,m+1,r,v);
	}

	segtree(vector<T> &v) : n(v.size()), seg(4*n) { build(1,0,n-1); }
	segtree(int n) : n(n), seg(4*n) {}

	ND update(int a, T x, int p, int l, int r) {
		if (a < l || r < a) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(a,x,2*p,l,m)+update(a,x,2*p+1,m+1,r);
	}

	ND query(int a, int b, int p, int l, int r){
		if (a <= l && r <= b) return seg[p];
		if (b < l || r < a) return ND();
		int m = (l+r)/2;
		return query(a,b,2*p,l,m)+query(a,b,2*p+1,m+1,r);
	}

	void update(int a, T x) { update(a,x,1,0,n-1); }
	ND query(int a, int b) { return query(a,b,1,0,n-1); }
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

