/**
 * Algorithm from el-vasito.
 * Area covered from multiple circles intersections. 
 *
 * Complexity: O(n^2 log n) with high constant
 **/

bool cmp(point a, point b, point o){
	a = a-o, b = b-o;
	return make_tuple(-a.side(), 0) < make_tuple(-b.side(), a^b);
}

vector<double> intercircles(vector<circle> &c){
	vector<double> cover(c.size()+1); // area covered by at least k circles
	for(int i=0; i<c.size(); i++){
		int k=1;
		vector<pair<point,int>> p = {{c[i].o+point(1,0)*c[i].r,0}, {c[i].o-point(1,0)*c[i].r,0}};

		for(int j=0; j<c.size(); j++){
			bool b0 = c[i].in(c[j]), b1 = c[j].in(c[i]);
			if(b0 and (!b1 or i<j)) k++;
			else if (!b0 and !b1){
				auto v = c[i]^c[j];
				if(v.size() == 2){
					p.pb({v[0],1}); p.pb({v[1],-1});
					if(cmp(v[1],v[0],c[i].o)) k++;
				}
			}
		}

		point o = c[i].o;
		sort(p.begin(), p.end(),
				[&o](auto a, auto b){ return cmp(a.first,b.first,o); });
	
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
