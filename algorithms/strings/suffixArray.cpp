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
#define MID ((l+r)/2)

#define sorv(a) sort(a.begin(),a.end())
#define revv(a) reverse(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
#define ins insert
#define pb push_back
#define lb lower_bound
#define ub upper_bound

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

string printArr(ll *arr,ll l,ll m=0){if(m==1){for(ll i=0;i<l;i++)cout<<arr[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<l;i++)cout<<i<<": "<<arr[i]<<endl;}return "";}
string printVct(vi v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0; i<sz(v);i++)cout<<i<<": "<<v[i]<<endl;}return "";}
string printVct2D(vector<vi>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j]<<" ";cout<<endl;}return "";}
string printVctPair(vii v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i].F<<":"<<v[i].S<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<sz(v);i++)cout<<i<<":  "<<v[i].F<<" : "<<v[i].S<<endl;}return "";}
string printVctPair2D(vector<vii>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j].F<<":"<<v[i][j].S<<" ";cout<<endl;}return "";}
string printMap(map<ll,ll>mp){cout<<endl;for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)cout<<it->F<<" -> "<<it->S<<endl;return "";}
string printSet(set<ll>st,ll m=0){set<ll>::iterator it;if(m){for(it=st.begin();it!=st.end();it++)cout<<*it<<" ";cout<<endl;}else{cout<<endl;for(it=st.begin();it!=st.end();it++)cout<<*it<<endl;}return "";}
void check(ll n){cout<<"CHECKPOINT "<<n<<"\n\n";}
#define dbg(x) cout<<#x<<":"<<x<<endl
#define dbg2(x,y) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<endl
#define dbg3(x,y,z) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<endl
#define dbg4(x,y,z,w) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<endl
#define dbg5(x,y,z,w,v) cout<<#x<<":"<<x<<"  "<<#y<<":"<<y<<"  "<<#z<<":"<<z<<"  "<<#w<<":"<<w<<"  "<<#v<<":"<<v<<endl
#define dbgp(x) cout<<#x<<":("<<x.F<<" "<<x.S<<")"<<endl
#define dbgp2(x,y) cout<<#x<<":("<<x.F<<","<<x.S<<")  "<<#y<<":("<<y.F<<","<<y.S<<")"<<endl
#define dbgp3(x,y,z) cout<<#x<<":("<<x.F<<","<<x.S<<")  "<<#y<<":("<<y.F<<","<<y.S<<")  "<<#z<<":("<<z.F<<","<<z.S<<")"<<endl

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

typedef pair<ii,ll> ii_i;

void count_sort(vector <ii_i> &a){
	ll n = sz(a);
	vi cnt(n,0), scnt(n);
	vector <ii_i> a_new(n);
	{
		for (ll i =0; i<n; i++) cnt[a[i].F.F]++;
		scnt[0] = 0;
		for (ll i =1; i<n; i++) scnt[i] = scnt[i-1] + cnt[i-1];
		for (ll i =0; i<n; i++){
			a_new[scnt[a[i].F.F]] = a[i];
			scnt[a[i].F.F]++;
		}
		a = a_new;
	}
}

vector <ii_i> a;
vi p, c;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	s+='$';
	ll n = sz(s), cur;
	p.resize(n), c.resize(n), a.resize(n);

	for (ll i =0; i<n; i++) a[i] = ii_i(ii(s[i],0), i);
	sorv(a);
	for (ll i = 0; i<n; i++) p[i] = a[i].S;
	cur = 0;
	c[p[0]] = cur;
	for (ll i =1; i<n; i++){
		if (a[i].F != a[i-1].F) cur++;
		c[p[i]] = cur;
	}

	ll k = 0, idx;
	while ((1<<k) < n){
		for (ll i =0; i<n; i++){
			idx = (p[i] - (1<<k) + n) % n;
			a[i] = ii_i(ii(c[idx],c[p[i]]), idx);
		}
		count_sort(a);
		for (ll i =0; i<n; i++) p[i] = a[i].S;
		cur = 0;
		c[p[0]] = cur;
		for (ll i =1; i<n; i++){
			if (a[i].F != a[i-1].F) cur++;
			c[p[i]] = cur;
		}
		k++;
	}
	
	for (ll i =0; i<n; i++)
		cout<<p[i]<<" ";
	return 0;
}

//Time Complexity: O(n * logn)

/*
ababba

aaaa

ppppplppp

nn
*/

































