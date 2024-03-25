// Disjoint set union

struct DSU {
	vector<int> p;

	DSU(int n) : p(n, -1) {}

	int find(int u) { return p[u] < 0? u: p[u] = find(p[u]); }

	int size(int u) { return -p[find(u)]; }

	bool same(int u, int v) { return find(u) == find(v); }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if(u == v) return false; 
		if(p[u] < p[v]) swap(u,v);
		p[u] += p[v]; p[v] = u;
		return true;
	}
};

