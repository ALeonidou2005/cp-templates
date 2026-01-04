//Andreas Leonidou | 03-01-2023

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <climits>

using namespace std;

#define ll long long
#define F first
#define S second
#define sz(x) (ll)x.size()

typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;


// ------------------------------- RANDOM GENERATOR TEMPLATE -------------------------------

class RandomGenerator{
private:
	static const ll N = 200000;
	mt19937 rng;

	void applyTreeIndexOffset(vii &edges, ll index_offset){
		for (ll i = 0; i<sz(edges); i++){
			edges[i].F += index_offset;
			edges[i].S += index_offset;
		}
	}

public:
	RandomGenerator(){
		rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
	}

	//------VALUES------

	ll getNum(ll l, ll r){	// l<=x<=r
		if (l > r){ cout<<endl<<"ERROR: RandomGenerator.genNum: Invalid Input (l: "<<l<<" r:"<<r<<")"<<endl; return LLONG_MIN;};
		return ((rng() % (abs(r-l)+1)) + l);
	}

	//------ARRAYS------

	vi getArr(ll n, ll l, ll r){
		if (l > r || n < 0 || n > N) { cout<<"ERROR: RandomGenerator.genArr: Invalid Input (n:"<<n<<" l:"<<l<<" r:"<<r<<")"<<endl; return vi();}
		vi ans(n);
		for (ll i =0; i<n; i++)
			ans[i] = getNum(l,r);
		return ans;
	}

	vi getPermutation(ll n, ll index_offset = 0){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getPermutation: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vi();}
		vi v(n);
		for (ll i=0; i<n; i++) v[i] = i + index_offset;
		shuffle(v.begin(), v.end(), rng);
		return v;
	}

	//------TREES------

	vii getTreeRandom(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeRandom: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i=1; i<n; i++){
			edges[i-1] = ii(getNum(0, i-1), i);
		}
		shuffle(edges.begin(), edges.end(), rng);
		vi randPerm = getPermutation(n);
		for (ll i =0; i<n-1; i++){
			if (getNum(0,1)) swap(edges[i].F, edges[i].S);
			edges[i] = ii(randPerm[edges[i].F], randPerm[edges[i].S]);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeBinary(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeBinary: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i = 1; i<n; i++){
			edges[i-1] = ii((i-1)/2, i);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeLine(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeLine: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i = 1; i<n; i++){
			edges[i-1] = ii(i-1, i);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeStar(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeStar: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		vii edges(n-1);
		for (ll i = 1; i<n; i++){
			edges[i-1] = ii(0, i);
		}
		applyTreeIndexOffset(edges, index_offset);
		return edges;
	}

	vii getTreeAny(ll n, ll index_offset = 1){
		if (n < 0) { cout<<"ERROR: RandomGenerator.getTreeAny: Invalid Input (n:"<<n<<" index_offset:"<<index_offset<<")"<<endl; return vii();}
		ll type = getNum(0, 7);
		vii edges;
		switch (type){		//Random:62.5%, Line:12.5%, Star:12.5%, Binary:12.5%
			case 0: case 1: case 2: case 3: case 4:
			edges = getTreeRandom(n, index_offset); break;
			case 5: 
			edges = getTreeLine(n, index_offset); break;
			case 6: 
			edges = getTreeStar(n, index_offset); break;
			case 7: 
			edges = getTreeBinary(n, index_offset); break;
		}
		return edges;
	}
};

RandomGenerator rnd;

// ----------------------------------------------------------------------------------------



































