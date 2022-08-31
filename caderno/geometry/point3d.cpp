typedef long double T;
const long double EPS = 1e-6;

struct point {
	T x,y,z;
	point() {};
	point(T x, T y, T z) : x(x), y(y), z(z) {}

	point operator+(const point& other) const { return {x+other.x, y+other.y, z+other.z}; }
	point operator-(const point& other) const { return {x-other.x, y-other.y, z-other.z}; }
	point operator*(T t) const { return {x*t, y*t, z*t}; };
	point operator/(T t) const { return {x/t, y/t, z/t}; };

	bool operator==(const point& other) const { return abs(x-other.x) < EPS and abs(y-other.y) < EPS and abs(z-other.z) < EPS; }
	bool operator!=(const point& other) const { return !(*this == other); }

	T operator%(const point& other) const { return (x*other.y + y*other.z + z*other.x) - (other.x*y + other.y*z + other.z*x); } // determinant
	T operator*(const point& other) const { return x*other.x + y*other.y + z*other.z; } // dot
	point operator^(const point& other) const { return {y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x}; } // cross
};

// =0: same plane, >0: above plane, <0: below plane
T orient(point a, point b, point c, point d){
	return ((b-a)^(c-a))*(d-a);
}

bool collinear(point a, point b, point c){
	return (b-a)%(c-a) == 0;
}
