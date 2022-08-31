typedef double T;

point ccw90(1,0);

struct circle {
	point o; T r;
	circle(point o, T r) : o(o), r(r) {}

	bool has(point p){ return (o-p).norm() <= r + EPS; }

	vector<point> operator^(circle c){
		vector<point> inter;

		T d = (o-c.o).norm();
		if(d > r + c.r + EPS or d + min(r,c.r) + EPS < max(r,c.r) ) return inter;

		T x = (d*d - c.r*c.r + r*r) / (2*d),
		  y = sqrt(r*r - x*x);

		point v = (c.o-o)/d;
		inter.pb(o + v*x - v.rot(ccw90)*y);
		if(y>EPS) inter.pb(o+v*x+v.rot(ccw90)*y);
		return inter;
	}

	bool in(circle c){ 
		double d = (o-c.o).norm();
		return d+r <= c.r + EPS; 
	}
};

point circumCenter(point a, point b, point c){
	b = b-a; c = c-a;
	assert((b^c) != 0); // a,b,c alligned = no circumcircle
	return a + (b*c.norm2()-c*b.norm2()).perp()/((b^c)*2);
}

