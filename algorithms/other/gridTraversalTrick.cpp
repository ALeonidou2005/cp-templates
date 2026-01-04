#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define F first
#define S second
#define endl "\n"
#define sz(x) (ll)(x).size()
#define pb push_back
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
#define endl "\n"

const ll dx[8]={1,-1,0,0,1,1,-1,-1}, dy[8]={0,0,1,-1,1,-1,1,-1};	//necessary for grid-trick implementation

#define N 100
ll arr[N+1][N+1];

ll n,m;
bool ok(ll x, ll y) { return x>=0 && y>=0 && x<n && y<n; }		//extra shortcut for validating coordinates

int main(){

	cin>>n>>m;

	ll x,y;
	cin>>x>>y;

	ll curX, curY;
	cout<<endl;
	if (ok(x,y)){
		for (ll i = 0; i<4; i++){		//passing through all neighbours with just a for loop
			curX = x+dx[i], curY = y+dy[i];
			if (ok(curX, curY)) cout<<curX<<" "<<curY<<endl;
		}
	}
	
	return 0;
}


/*
5 5
2 3

4 6
0 1

8 8
7 7
*/




























