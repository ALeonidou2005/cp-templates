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

#define N 100000
ll arr[N+1];

ll countElements(ll n, ll t){		//O(logn * 2)
	ll step, idxBefore, idxAfter, initialStep;

	//calculate max step
	{
		initialStep = 1;
		while (initialStep*2 <= n) initialStep*=2;
	}

	//find element before
	{
		step = initialStep, idxBefore = -1;
		while (step){
			if (idxBefore+step < n && arr[idxBefore+step] < t) idxBefore+=step;
			step /= 2;
		}
	}

	//find element after
	{
		step = initialStep, idxAfter = n;
		while (step){
			if (idxAfter-step >= 0 && arr[idxAfter-step] > t) idxAfter-=step;
			step /= 2;
		}	
	}

	return idxAfter-idxBefore-1;
}

ll posBefore(ll n, ll t){		//O(logn)
	ll step, idxBefore = -1;

	//calculate max step
	step = 1;
	while (step*2 <= n) step*=2;

	//find element before
	while (step){
		if (idxBefore+step < n && arr[idxBefore+step] < t) idxBefore+=step;
		step /= 2;
	}

	return idxBefore;
}

ll posAfter(ll n, ll t){		//O(logn)
	ll step, idxAfter = n;

	//calculate max step
	step = 1;
	while (step*2 <= n) step*=2;

	//find element after
	while (step){
		if (idxAfter-step >= 0 && arr[idxAfter-step] > t) idxAfter-=step;
		step /= 2;
	}
	return idxAfter;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, t;
	cin>>n>>t;

	for (ll i = 0; i<n; i++) cin>>arr[i];
	sort(arr,arr+n);
	//printArr(arr,n,1);

	cout<<endl;
	cout<<"posBefore("<<t<<"): "<<posBefore(n,t)<<endl<<endl;
	cout<<"posAfter("<<t<<"): "<<posAfter(n,t)<<endl<<endl;
	cout<<"countElements("<<t<<"): "<<countElements(n,t)<<endl<<endl;

	cout<<endl<<".";

	return 0;
}


/*
SAMPLE INPUT:

6 8
8 8 8 9 1 3

4 8
8 8 8 8

10 9
3 4 9 8 2 5 1 8 5 3

10 1
3 4 9 8 2 5 1 8 5 3

10 100
3 4 9 8 2 5 1 8 5 3

10 -1
3 4 9 8 2 5 1 8 5 3

5 6
8 2 2 3 1

5 2
8 2 2 3 1
*/ 

/*
CF EDU PROBLEMS REFERENCE: https://codeforces.com/edu/course/2/lesson/6/1/practice

*/

































