template <const int MOD>
struct Mint {
	int x;
	Mint(): x(0) {}
	Mint(int _x): x(_x%MOD<0?_x%MOD+MOD:_x%MOD) {}
	void operator+=(Mint rhs) { x+=rhs.x; if(x>=MOD) x-=MOD; }
	void operator-=(Mint rhs) { x-=rhs.x; if(x<0)x+=MOD; }
	void operator*=(Mint rhs) { x*=rhs.x; x%=MOD; }
	void operator/=(Mint rhs) { *this *= rhs.inv(); }
	Mint operator+(Mint rhs) { Mint res=*this; res+=rhs; return res; }
	Mint operator-(Mint rhs) { Mint res=*this; res-=rhs; return res; }
	Mint operator*(Mint rhs) { Mint res=*this; res*=rhs; return res; }
	Mint operator/(Mint rhs) { Mint res=*this; res/=rhs; return res; }
	Mint inv() { return this->pow(MOD-2); }
	Mint pow(int e) {
		Mint res(1);
		for (Mint p = *this; e > 0; e /= 2, p *= p) if (e%2)
			res *= p;
		return res;
	}
};

using mint = Mint<998244353>;
