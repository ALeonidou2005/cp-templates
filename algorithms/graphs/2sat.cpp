// Problem: CSES - Giant Pizza - 2-SAT: https://cses.fi/problemset/task/1684
// Date: 14/07/2024
// Author: ALeonidou

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

vector <vi> adj, radj, cadj, fadj;
stack <ll> st;
vi vis;

void dfs1(ll u){
	vis[u] = 1;
	for (ll i=0; i<sz(adj[u]); i++){
		if (!vis[adj[u][i]]){
			dfs1(adj[u][i]);
		}
	}
	st.push(u);
}

void dfs2(ll u){
	vis[u] = sz(cadj);
	cadj.back().pb(u);
	for (ll i =0; i<sz(radj[u]); i++){
		ll c = radj[u][i];
		if (!vis[c]){
			dfs2(c);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, m;
	cin>>n>>m;

	char a,b;
	ll x, y;
	adj.assign(m*2, vi());	//variables in pairs => 2k is TRUE, 2k+1 is FALSE
	radj.assign(m*2, vi());
	for (ll i =0; i<n; i++){
		cin>>a>>x>>b>>y;	x--, y--;
		ll x_pos = 2*x + (a == '-');
		ll x_neg = x_pos ^ 1;
		ll y_pos = 2*y + (b == '-');
		ll y_neg = y_pos ^ 1;
		//~X implies Y:
		adj[x_neg].pb(y_pos);
		radj[y_pos].pb(x_neg);
		//~Y implies X:
		adj[y_neg].pb(x_pos);
		radj[x_pos].pb(y_neg);
	}
	// cout<<endl<<"adj:";
	// printVct2D(adj);
	
	vis.assign(sz(adj), 0);
	for (ll i =0; i<sz(adj); i++){
		if (!vis[i]){
			dfs1(i);
		}
	}	

	vis.assign(sz(adj), 0);
	while (!st.empty()){
		ll f = st.top();
		st.pop();
		if (vis[f]) continue;
		cadj.pb(vi());
		vis[f] = sz(cadj);
		dfs2(f);
	}

	// cout<<endl<<"cadj:";
	// printVct2D(cadj);

	bool ans = true;
	vi ans_values(m, -1);
	for (ll i =0; i<sz(vis); i+=2){
		if (vis[i] == vis[i+1]){
			ans = false;
			break;
		}
		else if (vis[i] < vis[i+1]){
			ans_values[i/2] = 0;
		}
		else{
			ans_values[i/2] = 1;
		}
	}

	// cout<<endl<<"vis: ";
	// printVct(vis);
	
	if (!ans){
		cout<<"IMPOSSIBLE"<<endl;		
	}
	else{
		for (ll i =0; i<sz(ans_values); i++){
			if (ans_values[i]) cout<<"+ ";
			else cout<<"- ";
		}
		cout<<endl;
	}
	
	return 0;
}


/*
3 5
+ 1 + 2
- 1 + 3
+ 4 - 2
*/

































