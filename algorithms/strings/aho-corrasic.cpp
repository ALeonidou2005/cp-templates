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


#define B 26	//size of alphabet

class Trie{
private:
	vector <vi> g;
	vi suf, rev_suf;
	vi ends;	//list of nodes that are ends of strings
	vi mini, maxi;
	stack <ll> from_bottom_to_top; 

public:
	void init(){
		g.assign(1, vi(B, -1));
		ends.clear();
	}

	ll new_node(){
		g.pb(vi(B, -1));
		return sz(g)-1;
	}

	void add(ll v, ll idx, const string &s){
		if (idx >= sz(s)){
			ends.pb(v);
			return;
		}
		if (g[v][charToIntLower(s[idx])] == -1){
			g[v][charToIntLower(s[idx])] = new_node();
		}
		add(g[v][charToIntLower(s[idx])], idx+1, s);
	}

	void aho_corasick(){
		suf.assign(sz(g), 0);

		queue <iii> q;	//node, parent node

		//root:
		suf[0] = -2;	//root has no suffix link
		for (ll i = 0; i<sz(g[0]); i++){
			if (g[0][i] == -1){
				g[0][i] = 0;
			}
		}

		//1st layer
		for (ll i = 0; i<sz(g[0]); i++){
			ll c = g[0][i];
			if (c != 0){
				from_bottom_to_top.push(c);
				suf[c] = 0;
				for (ll j = 0; j<sz(g[c]); j++){
					if (g[c][j] != -1) {
						q.push(iii(g[c][j], ii(c, j)));
					}
					else{
						g[c][j] = g[suf[c]][j];
					}
				}
			}
		}

		//build other layers:
		while (!q.empty()){
			iii f = q.front();
			q.pop();
			ll u = f.F, p = f.S.F, c = f.S.S;
			from_bottom_to_top.push(u);
			for (ll i =0; i<sz(g[u]); i++){
				//no vis => always downwards
				if (g[u][i] != -1){
					q.push(iii(g[u][i], ii(u, i)));
				}
			}

			//calc:
			suf[u] = g[suf[p]][c];
			for (ll i = 0; i<sz(g[u]); i++){
				if (g[u][i] == -1){
					g[u][i] = g[suf[u]][i];
				}
			}
		}
	}

	vii solve(const string &t){
		mini.assign(sz(g), INF), maxi.assign(sz(g), -1);
		ll u = 0;
		mini[u] = 0;
		maxi[u] = 0;
		for (ll i = 0; i<sz(t); i++){
			u = g[u][charToIntLower(t[i])];
			mini[u] = min(mini[u], i);
			maxi[u] = max(maxi[u], i);
		}

		stack <ll> st = from_bottom_to_top;
		while (!st.empty()){
			ll f = st.top();
			st.pop();
			mini[suf[f]] = min(mini[suf[f]], mini[f]);
			maxi[suf[f]] = max(maxi[suf[f]], maxi[f]);
		}

		vii ans(sz(ends), ii(-1,-1));
		for (ll i = 0; i<sz(ends); i++){
			if (mini[ends[i]] != (ll)INF){
				ans[i] = ii(mini[ends[i]], maxi[ends[i]]);
			}
		}

		return ans;
	}

	void dbgTrie(){
		cout<<"g: "<<endl;
		for (ll i = 0; i<sz(g); i++){
			cout<<i<<": ";
			for (ll j =0; j<sz(g[i]); j++){
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"suf: "<<endl;
		for (ll i = 0; i<sz(suf); i++){
			cout<<i<<": "<<suf[i]<<endl;
		}
		cout<<endl<<endl;;
		cout.flush();
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;

	string s[n];
	for (ll i =0; i<n; i++){
		cin>>s[i];
	}

	string t;
	cin>>t;

	//build trie
	Trie trie;
	trie.init();
	for (ll i =0; i<n; i++){
		trie.add(0, 0, s[i]);
	}

	//aho-corrasic
	trie.aho_corasick();

	//solve
	vii ans = trie.solve(t);
	for (ll i = 0; i<n; i++){
		if (ans[i].F == -1){
			cout<<"-1 -1"<<endl;
		}
		else{
			cout<<(ans[i].F-sz(s[i])+1)<<" "<<(ans[i].S-sz(s[i])+1)<<endl;
		}
	}
	
	return 0;
}


/*
7
2 2 a 4 b
2 3 a 6 b
0
1 5 b
1 7 b
0
0
4
b
bb
bbb
bb




*/

































