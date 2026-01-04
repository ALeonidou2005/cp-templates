//https://michanicos.cmscoinformatics.org/#/task/cirgle/statement
//(Cirgle: COI2021C)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define F first
#define S second
#define endl "\n"
#define MID ((l+r)/2)

#define sorv(a) sort(a.begin(),a.end())
#define revv(a) reverse(a.begin(),a.end())
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
typedef vector <iii> viii;
typedef set <ll> si;
typedef map <ll,ll> mi;

#ifndef ONLINE_JUDGE
	//#define ONLINE_JUDGE
#endif

#ifndef ONLINE_JUDGE 
	template<typename T>void printArr(T *arr,ll l,ll m=0){if(m==1){for(ll i=0;i<l;i++)cout<<arr[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<l;i++)cout<<i<<": "<<arr[i]<<endl;}}
	#define printArr2D(arr,n,m)cout<<endl;for(ll i=0;i<n;i++){for(ll j=0;j<m;j++)cout<<arr[i][j]<<" ";cout<<endl;}cout<<endl;
	template<typename T>void printVct(vector<T> v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0; i<sz(v);i++)cout<<i<<": "<<v[i]<<endl;}}
	template<typename T>void printVct2D(vector<vector<T> >v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j]<<" ";cout<<endl;}}
	template<typename T>void printVctPair(vector<T> v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i].F<<":"<<v[i].S<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<sz(v);i++)cout<<i<<":  "<<v[i].F<<" : "<<v[i].S<<endl;}}
	template<typename T>void printVctPair2D(vector<vector<T> >v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j].F<<":"<<v[i][j].S<<" ";cout<<endl;}}
	template<typename T>void printVctPair3(vector<T> v,ll m=0){cout<<endl;for(ll i=0;i<sz(v);i++)cout<<i<<": ("<<v[i].F<<" : "<<v[i].S.F<<" : "<<v[i].S.S<<")"<<endl;}
	template<typename T1,typename T2>void printMap(map<T1,T2>mp){cout<<endl;for(typename map<T1,T2>::iterator it=mp.begin();it!=mp.end();it++)cout<<it->F<<" -> "<<it->S<<endl;}
	template<typename T>void printSet(set<T>st,ll m=0){typename set<T>::iterator it;if(m){for(it=st.begin();it!=st.end();it++)cout<<*it<<" ";cout<<endl;}else{cout<<endl;for(it=st.begin();it!=st.end();it++)cout<<*it<<endl;}}
	void check(ll n){cout<<"CHECKPOINT "<<n<<"\n\n";}
	#define dbg(x) cout<<#x<<":"<<x<<endl
	#define dbg2(x,y) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<endl
	#define dbg3(x,y,z) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<endl
	#define dbg4(x,y,z,w) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<endl
	#define dbg5(x,y,z,w,v) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<"  "<<#v<<":"<<v<<endl
	#define dbg6(x,y,z,w,v,u) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<"  "<<#v<<":"<<v<<"  "<<#u<<":"<<u<<endl
	#define dbgp(x) cout<<#x<<":("<<x.F<<" "<<x.S<<")"<<endl
	#define dbgp2(x,y) cout<<#x<<":("<<x.F<<","<<x.S<<")  "<<#y<<":("<<y.F<<","<<y.S<<")"<<endl
	#define dbgt(x) cout<<#x<<":("<<x.F<<" "<<x.S.F<<" "<<x.S.S<<")"<<endl
	#define dbgt2(x,y) cout<<#x<<":("<<x.F<<" "<<x.S.F<<" "<<x.S.S<<")  "<<#y<<":("<<y.F<<" "<<y.S.F<<" "<<y.S.S<<")"<<endl
#else
	template<typename T>void printArr(T *arr,ll l,ll m=0){}
	#define printArr2D(arr,n,m)
	template<typename T>void printVct(vector<T> v,ll m=0){}
	template<typename T>void printVct2D(vector<vector<T> >v){}
	template<typename T>void printVctPair(vector<T> v,ll m=0){}
	template<typename T>void printVctPair2D(vector<vector<T> >v){}
	template<typename T>void printVctPair3(vector<T> v,ll m=0){}
	template<typename T1,typename T2>void printMap(map<T1,T2>mp){}
	template<typename T>void printSet(set<T>st,ll m=0){}
	void check(ll n){}
	#define dbg(x)
	#define dbg2(x,y)
	#define dbg3(x,y,z)
	#define dbg4(x,y,z,w)
	#define dbg5(x,y,z,w,v)
	#define dbg6(x,y,z,w,v,u)
	#define dbgp(x)
	#define dbgp2(x,y)
	#define dbgt(x)
	#define dbgt2(x,y)
#endif

const ll dx[8]={1,-1,0,0,1,1,-1,-1}, dy[8]={0,0,1,-1,1,-1,1,-1};

ll charToIntNum(char c){return (ll)c-48;} 
char intToCharNum(ll n){return (char)n+48;}
ll charToIntLower(char c){return (ll)c-97;}
char intToCharLower(ll n){return (char)n+97;}
ll charToIntUpper(char c){return (ll)c-65;}
char intToCharUpper(ll n){return (char)n+65;}

void tabb(ll n){for(ll i=0;i<n;i++)cout<<"\t";}
ll gcd(ll x,ll y){if(y==0)return x;return gcd(y,x%y);}
void yesno(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}

ld distance(ld x1, ld y1, ld x2, ld y2){
	ld a = (x2-x1) * (x2-x1), b = (y2-y1) * (y2-y1);
	return sqrtl(a + b);
}

const ld EPS = 0.0000000001; //1e-9
ld min_distance_of_line_semgnet_and_point(ld a, ld b, ld x1, ld y1, ld x2, ld y2){
	ld l = 0, r = 1, mid1, mid2;
	ld ans = -1;
	ld dis = distance(x1, y1, x2, y2);
	while (dis * (r - l) >= EPS){
		mid1 = l + (r - l) / (ld)3.0;		//first third
		mid2 = r - (r - l) / (ld)3.0;		//second third
		//calc point = point + (dif * percentage)
		ld px1 = x1 + (x2-x1) * mid1;
		ld py1 = y1 + (y2-y1) * mid1;
		ld px2 = x1 + (x2-x1) * mid2;
		ld py2 = y1 + (y2-y1) * mid2;

		ld dis1 = distance(px1, py1, a, b);
		ld dis2 = distance(px2, py2, a, b);

		if (dis1 < dis2){
			r = mid2;
			ans = dis1;
		}
		else{
			l = mid1;
			ans = dis2;
		}
	}
	return ans;
}

bool solvePoint(ld a, ld b, ld r, ld x, ld y){
	ld dis = distance(a,b,x,y);
	return (dis >= r);
}

bool solveLine(ld a, ld b, ld r, ld x1, ld y1, ld x2, ld y2){
	ld dis = min_distance_of_line_semgnet_and_point(a, b, x1, y1, x2, y2);
	return (dis-EPS <= r);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll t;
	cin>>t;

	ld a, b, r, x[3], y[3];
	while (t--){
		cin>>a>>b>>r;
		for (ll i=0; i<3; i++) cin>>x[i]>>y[i];
		bool point_touch_or_out = false, line_touch_or_in = false;
		for (ll i= 0; i<3; i++){
			point_touch_or_out |= solvePoint(a, b, r, x[i], y[i]);
			for (ll j=i+1; j<3; j++){
				line_touch_or_in |= solveLine(a, b, r, x[i], y[i], x[j], y[j]);
			}
		}
		bool ans = (point_touch_or_out && line_touch_or_in);
		yesno(ans);
	}
	
	return 0;
}


/*
6
0 0 4
2 3
4 8
7 6
0 4 4
4 0
4 4
9 0
0 4 4
-2 3
2 6
2 3
-5 4 2
2 6
4 7
6 3
0 5 4
4 2
4 8
8 8
0 2 4
4 2
8 2
8 8
*/

































