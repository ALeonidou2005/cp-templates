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


vector <vii> adj;
vi vis, dp;
ll dfs1(ll u, ll p = -1){
	ll ans = 0;
	for (ll i =0; i<sz(adj[u]); i++){
		if (p == adj[u][i].F) continue;
		ans += dfs1(adj[u][i].F, u) + adj[u][i].S;
	}
	return ans;
}

void dfs2(ll u, ll p = -1){
	for (ll i =0; i<sz(adj[u]); i++){
		if (p == adj[u][i].F) continue;
		if (adj[u][i].S == 0) dp[adj[u][i].F] = dp[u] + 1;
		else dp[adj[u][i].F] = dp[u] - 1;
		dfs2(adj[u][i].F, u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;

	adj.assign(n, vii());
	ll a,b;
	for (ll i =0; i<n-1; i++){
		cin>>a>>b;
		a--,b--;
		adj[a].pb(ii(b,0));
		adj[b].pb(ii(a,1));
	}

	vis.assign(n, 0);
	dp.resize(n);
	dp[0] = dfs1(0);
	// dbg(dp[0]);
	dfs2(0);

	// printVct(dp);
	
	ll mini = dp[0], ans = 1;
	for (ll i =0; i<n; i++){
		if (mini > dp[i]){
			mini = dp[i];
			ans = 1;
		}
		else if (mini == dp[i]){
			ans++;
		}
	}

	cout<<mini<<endl;
	for (ll i=0; i<n; i++){
		if (dp[i] == mini){
			cout<<(i+1)<<" ";
		}
	}
	cout<<endl;
	
	return 0;
}


/*
3
2 1
2 3

*/


































