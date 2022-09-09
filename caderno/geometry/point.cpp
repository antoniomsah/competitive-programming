typedef double T;
const double EPS = 1e-7;

int sign(T x) { return (x > EPS) - (x < -EPS); }

struct point {
	T x,y;
	
	point() {}
	point(T x, T y) : x(x), y(y) {}
	
	T norm2(){ return *this * *this; }
	T norm(){ return sqrt(norm2()); }

	point operator+(const point& other) const { return {x+other.x, y+other.y}; }
	point operator-(const point& other) const { return {x-other.x, y-other.y}; }
	point operator*(const T t) const { return {x*t, y*t}; }
	point operator/(const T t) const { return {x/t, y/t}; }

	T operator^(const point& other) const { return x*other.y - y*other.x; } // cross
	T operator*(const point& other) const { return x*other.x + y*other.y; } // dot

	bool operator<(const point& other) const { return x < other.x - EPS or (abs(x-other.x) < EPS and y < other.y - EPS); }
	bool operator==(const point& other) const { return abs(x-other.x) < EPS and abs(y-other.y) < EPS; }
	bool operator!=(const point& other) const { return !(*this == other); }

	bool is_perp(const point& other) const { return abs(*this * other) < EPS; }
	point rot(const point& other) const { return point(*this ^ other, *this * other); }
	point rot(double a){ return rot(point(sin(a), cos(a))); }
	point perp(){ return {-y,x}; }

	double angle(point other) {
		return acos( max(T(-1), min(T(1), *this * other / (norm() * other.norm()) )) );
	}

	bool side(){ return y > EPS or (abs(y) < EPS and x < EPS); }
};

double abs(point p) { return sqrt(p.norm2()); }

// >0: left, <0: right, =0, collinear
T area2(point a, point b, point c){
	return (b-a)^(c-a);
}

T dist2(point a, point b){
	return (b-a).norm2();
}

void polarsort(vector<point> &v){
	sort(v.begin(), v.end(), [](point a, point b){
			return make_tuple(a.side(),0) < make_tuple(b.side(),a^b);
			});
}

// for debugging
ostream& operator<<(ostream& os, point p){ return os<<"("<<p.x<<","<<p.y<<")"; }

