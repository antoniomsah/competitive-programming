// Persistent Segment Tree
//
// Details: MUST run build, it creates the root version

template <typename T>
struct persistent_segment_tree {
	const int LIM = 1e7;
    int n, rt, nxt;
    vector<T> seg; 
	vector<int> L, R;

	persistent_segment_tree(int n): seg(LIM), L(LIM), R(LIM), n(n), nxt(0) {}

	int new_node(T x, int l=0, int r=0) {
		int id = nxt++;
		seg[id] = x; L[id] = l; R[id] = r;
		return id;
	}

	int build(vector<T> &v, int l, int r) {
		if (l == r) return new_node(v[l]);
		int m = (l+r)/2, tl = build(v,l,m), tr = build(v,m+1,r);
		return new_node(seg[tl]+seg[tr], tl, tr);
	}

	int build(vector<T> &v) { return rt = build(v,0,n-1); }

	int update(int p, T x, int k, int l, int r) {
		int id = new_node(seg[k],L[k],R[k]);
		if (l == r) { seg[id] = x; return id; }

		int m = (l+r)/2;
		if (p <= m) L[id] = update(p,x,L[id],l,m);
		else R[id] = update(p,x,R[id],m+1,r);
		seg[id] = seg[L[id]] + seg[R[id]];
		return id;
	}

	T query(int a, int b, int k, int l, int r) {
		if (r < a or b < l) return 0;
		if (a <= l and r <= b) return seg[k];
		int m = (l+r)/2;
		return query(a,b,L[k],l,m) + query(a,b,R[k],m+1,r);
	}

	int update(int p, T x, int t) { return rt = update(p,x,t,0,n-1); }
	int update(int p, T x) { return update(p,x,rt); }
	T query(int l, int r, int t) { return query(l,r,t,0,n-1); }
};
