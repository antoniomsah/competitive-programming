// Range Minimum Queries

template <class T>
struct RMQ {
	vector<vector<T>> dp;

	RMQ(const vector<T>& v) : dp(1, v) {
		for (int pw = 1, k = 1; pw * 2 <= v.size(); pw *= 2, ++k) {
			dp.emplace_back(v.size() - pw * 2 + 1);
			for (int j = 0; j < dp[k].size(); j++) 
				dp[k][j] = f(dp[k - 1][j], dp[k - 1][j + pw]);
		}
	}

	T f(T a, T b) { return min(a, b); }

	T query(int a, int b) {
		if (a == b) return dp[0][a];
		int dep = 63 - __builtin_clzll(b - a);
		return f(dp[dep][a], dp[dep][b - (1 << dep)]);
	}
};
