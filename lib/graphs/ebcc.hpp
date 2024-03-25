// Tarjan's algorithm for edge biconnected components

namespace tarjan {
	const int MAXN = 2e5+10;

	int nebcc = 0;
	vector<int> ebcc(MAXN), sz;

	void build(int n, vector<vector<int>> adj) {
		int t=0, sn=0;
		vector<int> disc(n,-1), low(n,-1), stk(n);

		function<void(int,int)> dfs = [&](int u, int p) {
			disc[u] = low[u] = t++;
			stk[sn++] = u;
			for (auto v: adj[u]) {
				if (disc[v] == -1) {
					dfs(v,u);
					low[u] = min(low[u], low[v]);
				}
				else if (v != p) {
					low[u] = min(low[u], disc[v]);
				}
			}

			if (low[u] == disc[u]) {
				int v;
				sz.emplace_back(0);
				do {
					v = stk[--sn];
					ebcc[v] = nebcc;
					sz[nebcc]++;
				} while (u != v);
				nebcc++;
			}
		};

		for (int u = 0; u < n; u++) {
			if (disc[u] == -1) dfs(u, u);
		}
	}
};
