// --------------------------------- GEOMETRY TEMPLATE ---------------------------------

struct P{
	ll x,y;

	P(ll xx = 0, ll yy = 0){
		x = xx;
		y = yy;
	}

	void read(){
		cin>>x>>y;
	}

	P operator-(const P &b) const{
		return P(x - b.x, y - b.y);
	}

	P operator+(const P &b) const{
		return P(x + b.x, y + b.y);
	}

	void operator-=(const P &b){
		x -= b.x, y -= b.y;
	}

	void operator+=(const P &b){
		x += b.x, y += b.y;
	}

	ll operator*(const P &b) const{
		return (x * b.y - y * b.x);
	}
};

// ----------------------------------------------------------------------------------------
