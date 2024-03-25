// Tarjan's algorithm for strongly connected components

namespace tarjan {
	constexpr int MAXN = 2e5+10;
	constexpr int INF = 1e9;

	int nscc = 0;
	vector<int> scc(MAXN), sz;

	void build(int n, vector<vector<int>>& adj) {
		int t=0, sn=0;
		vector<int> disc(n,-1), low(n,-1), stk(n);

		function<void(int)> dfs = [&](int u) {
			disc[u] = low[u] = t++;
			stk[sn++] = u;
			for (auto v: adj[u]) {
				if (disc[v] == -1) dfs(v);
				low[u] = min(low[u], low[v]);
			}
			if (low[u] == disc[u]) {
				int v;
				sz.emplace_back(0);
				do {
					v = stk[--sn];
					scc[v] = nscc;
					sz[nscc]++;
					low[v] = INF;
				} while(u != v);
				nscc++;
			}
		};

		for (int u = 0; u < n; u++) 
			if (disc[u] == -1) dfs(u);
	}
};
