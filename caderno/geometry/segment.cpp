struct segment {
	point p,q;

	segment(point p, point q) : p(p), q(q) {};
	bool inDisk(point r){ return (a-r)*(b-r) < EPS; }
	bool has(point r) { return abs(area2(p,q,r)) < EPS and inDisk(r); }
};
