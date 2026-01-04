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

#define N 2500
ll dis[N+1];

viii e;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n,m;
	cin>>n>>m;

	ll a,b,w;
	for (ll i =0; i<m; i++){
		cin>>a>>b>>w;
		e.pb(iii(a-1, ii(b-1,w)));
	}

	//Bellman-Ford Algorithm
	dis[0] = 0;
	for (ll i = 1; i<n; i++)
		dis[i] = -INF;
	for (ll i =0; i<n-1; i++){
		for (ll j=0; j<m; j++){
			a = e[j].F, b= e[j].S.F, w = e[j].S.S;
			if (dis[a] == -INF) continue;
			dis[b] = max(dis[b], dis[a] + w);
		}
	}

	//Cycle Detection (extension)
	bool ok = true;
	for (ll i =0; i<m; i++){
		a = e[i].F, b= e[i].S.F, w = e[i].S.S;
		if (dis[a] == -INF) continue;
		if (dis[b] < dis[a] + w){
			ok = false;
			break;
		}
	}
	//----------------

	if (ok) cout<<dis[n-1]<<endl;
	else cout<<"Cycle Detected"<<endl;
	
	return 0;
}


/*
NOTES:
• Longest shortest path is always at most n-1 edges long. So, if there are no infinite cycles, the final distances are guaranteed to be calculated in (n-1) iterations. To detect infinite cycle, simply run the algorithm another (nth) time. If a distance update occurs, a cycle is present. 
• The line "if (dis[a] == -INF) continue;" is very important as without it you lose the information of whether the node is actually reachable by the starting node or not. (INF changes to INF-2, and it is no longer recognisable as an unreachable node). Also, ignoring it from the cycle detection part, will result into also detecting cycles which are not reachable by the starting node.
• Time Complexity: O(n*m) => O(n^2)
• Good Problem: CSES - Graph Algorithms - High Score
*/

/*
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

=> 5
*/

































