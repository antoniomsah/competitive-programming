/**
 * Algorithm from el-vasito.
 * Area covered from multiple circles intersections. 
 *
 * Complexity: O(n^n log n) with high constant
 **/

struct Cmp {
	point r;
	Cmp(point r) : r(r) {}

	int cuad(const point& a) const {
		if(a.x > 0 and a.y >= 0) return 0;
		if(a.x <= 0 and a.y > 0) return 1;
		if(a.x < 0 and a.y <= 0) return 2;
		if(a.x >= 0 and a.y < 0) return 3;
		return -1;
	}

	bool cmp(const point& a, const point& b) const {
		int c1 = cuad(a), c2 = cuad(b);
		if(c1 == c2) return a.y*b.x < a.x*b.y;
		return c1 < c2;
	}

	bool operator()(const point& a, const point& b){ return cmp(a-r,b-r); }
};

vector<point> intercircles(vector<circle> &c){
	vector<double> cover(c.size()+1); // area covered by at least k circles
	for(int i=0; i<c.size(); i++){
		int k=1;
		Cmp s(c[i].o);
		vector<pair<point,int>> p = {{c[i].o+point(1,0)*c[i].r,0}, {c[i].o-point(1,0)*c[i].r,0}};

		for(int j=0; j<c.size(); j++){
			bool b0 = c[i].in(c[j]), b1 = c[j].in(c[i]);
			if(b0 and (!b1 or i<j)) k++;
			else if (!b0 and !b1){
				auto v = c[i]^c[j];
				if(v.size() == 2){
					p.pb({v[0],1}); p.pb({v[1],-1});
					if(s(v[1],v[0])) k++;
				}
			}
		}

		sort(p.begin(), p.end(),
				[&s](auto a, auto b){ return s(a.first, b.first); });
	
		for(int j=0; j<p.size(); j++){
			point a = p[j? j-1: p.size()-1].first, // (j-1+p.size())%p.size()
				  b = p[j].first;
			double ang = (a-c[i].o).angle(b-c[i].o);
			cover[k] += (a.x-b.x)*(a.y+b.y)/2 + c[i].r * c[i].r * (ang-sin(ang))/2;
			k += p[j].second;
		}
	}

	return cover;
}
