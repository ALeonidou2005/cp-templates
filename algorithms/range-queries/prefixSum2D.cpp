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

#define N 1000

ll arr[N+1][N+1];
ll s[N+1][N+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	for (ll i =0; i<n; i++)
		for (ll j = 0; j<n; j++)
			cin>>arr[i][j];

	//prefix sum
	s[0][0] = arr[0][0]; 
	for (ll i = 1; i<n; i++){
		s[i][0] = s[i-1][0] + arr[i][0];
		s[0][i] = s[0][i-1] + arr[0][i];
	}
	for (ll i = 1; i<n; i++){
		for (ll j = 1; j<n; j++){
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + arr[i][j];
		}
	}

	//output
	for (ll i = 0; i<n; i++){
		for (ll j = 0; j<n; j++)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}

//FOR 2D PREFIX SUM QUERIES:
/*
	ll x1,x2,y1,y2;
	while (q--){
		cin>>x1>>y1>>x2>>y2;
		cout<<s[x2][y2] + s[x1-1][y1-1] - s[x2][y1-1] - s[x1-1][y2]<<endl;
	}
*/
	
	return 0;
}

/*
3
4 6 9
1 3 8
6 2 6

5
1 4 6 0 2
4 3 8 5 0
1 4 0 9 2
3 1 8 8 2
7 3 4 3 4
*/


//CSES PROBLEM REFERENCE: https://cses.fi/problemset/result/5492965/






























