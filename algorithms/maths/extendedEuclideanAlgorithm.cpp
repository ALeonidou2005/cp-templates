#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <string>
#include <fstream>

using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define F first
#define S second
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
#define ins insert
#define pb push_back

#define inf 1e9
#define INF 1e18
#define MOD 1000000007
#define MOD2 998244353

typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef set <ll> si;
typedef map <ll,ll> mi;

string printArr(ll *arr,ll l,ll m=0){if(m==1){for(ll i=0;i<l;i++)cout<<arr[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<l;i++)cout<<i<<": "<<arr[i]<<endl;}return "";}
string printVct(vi v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0; i<sz(v);i++)cout<<i<<": "<<v[i]<<endl;}return "";}
string printVct2D(vector<vi>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j]<<" ";cout<<endl;}return "";}
string printVctPair(vii v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i].F<<":"<<v[i].S<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<sz(v);i++)cout<<i<<":  "<<v[i].F<<" : "<<v[i].S<<endl;}return "";}
string printVctPair2D(vector<vii>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j].F<<":"<<v[i][j].S<<" ";cout<<endl;}return "";}
void check(ll n){cout<<"CHECKPOINT "<<n<<"\n\n";}
#define dbg(x) cout<<#x<<":"<<x<<endl
#define dbg2(x,y) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<endl
#define dbg3(x,y,z) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<endl
#define dbg4(x,y,z,w) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<endl

const ll dx[8]={1,-1,0,0,1,1,-1,-1}, dy[8]={0,0,1,-1,1,-1,1,-1};

ll charToIntNum(char c){return (ll)c-48;} 
char intToCharNum(ll n){return (char)n+48;}
ll charToIntLower(char c){return (ll)c-97;}
char intToCharLower(ll n){return (char)n+97;}
ll charToIntUpper(char c){return (ll)c-65;}
char intToCharUpper(ll n){return (char)n+65;}

ll gcd(ll x,ll y){if(y==0)return x;return gcd(y,x%y);}
void yesno(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}

//Calculating x and y and d (d = gcd)
ll extended_gcd(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1;
		y = 0;	//anything
		return a;
	}
	ll d = extended_gcd(b, a%b, x, y);
	ll x1 = x,y1 = y;
	x = y1;
	y = x1 - a/b * y1;
	return d;
}

/*
NOTE: Alternative for general case 

	ll x1,y1;
	ll d = extended_gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - a/b * y1;
	return d;

WHY: The only difference is that x1 and x2 are already assigned values from lower recursion step. Thus, this implementation is just 2 assignment operations faster than the implementattion above.
WHY NOT: The method above is more intuitive and more similar to the math.
*/

//Calculating x and y without calculating the gcd
ii extended_gcd_without_gcd(ll a, ll b){
	if (b == 0) return ii(1,0);
	ii xy = extended_gcd_without_gcd(b, a%b);
	ll x = xy.S, y = xy.F - a/b * xy.S;
	return ii(x, y);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll a,b;
	cin>>a>>b;

	ll x,y,d;
	d = extended_gcd(a,b,x,y);
	
	dbg3(d,x,y);

	ii xy = extended_gcd_without_gcd(a,b);
	dbg2(xy.F, xy.S);
	
	return 0;
}

/*

SAMPLE INPUT:
2014 246

SAMPLE OUTPUT:
d = 2, x = -16, y = 131


REFERENCES:
• https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
• https://www.youtube.com/watch?v=hf-PRdtzqTY
*/
































