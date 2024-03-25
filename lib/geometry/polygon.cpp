struct polygon {
	int n;
	vector<point> p;
	polygon() {}
	polygon(vector<point> q) : n(q.size()), p(q) {}

	T calipers(){ // O(n), caderno enrique
		T ans=0;
		for(int i=0,j=1; i<n; i++){
			while(((p[(i+1)%n]-p[i])^(p[(j+1)%n]-p[j])) > 0) j = (j+1)%n;
			ans = max(ans, dist2(p[i],p[j])); // squared diameter.
		}
		return ans;
	}
};
