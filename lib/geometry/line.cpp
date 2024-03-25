struct line {
	point v; // v = q-p
	T c;

	line(point v, T c) : v(v), c(c) {}
	line(T a, T b, T c) : v({b,-a}), c(c) {}
	line(point p, point q) : v(q-p), c(v^p) {}

	// > 0: above, < 0 below, =0: colinear
	T side(point p) { return (v^p)-c; }
	T dist(point p) { return abs(side(p))/abs(v); }
	T dist2(point p) { return side(p)*side(p)/v.norm2(); }

	line perp(point p) { return {p, p+v.perp()}; }
	point proj(point p) { return p - v.perp()*side(p)/v.norm2(); }
};

// q is the intersection
bool inter(line l1, line l2, point &q){
	T d = l1.v^l2.v;
	if(d == 0) return false;
	q = (l2.v*l1.c - l1.v*l2.c)/d;
	return true;
}
