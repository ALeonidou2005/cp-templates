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
#define pb push_back
 
#define inf 1e9
#define INF 1e18
#define MOD 1000000007
#define MOD2 998244353
 
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
 
string printArr(ll *arr,ll l,ll m=0){if(m==1){for(ll i=0;i<l;i++)cout<<arr[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<l;i++)cout<<i<<": "<<arr[i]<<endl;}return "";}
string printVct(vi v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i]<<" ";cout<<endl;}else{cout<<endl;for(ll i=0; i<sz(v);i++)cout<<i<<": "<<v[i]<<endl;}return "";}
string printVct2D(vector<vi>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j]<<" ";cout<<endl;}return "";}
string printVctPair(vii v,ll m=0){if(m==1){for(ll i=0;i<sz(v);i++)cout<<v[i].F<<":"<<v[i].S<<" ";cout<<endl;}else{cout<<endl;for(ll i=0;i<sz(v);i++)cout<<i<<":  "<<v[i].F<<" : "<<v[i].S<<endl;}return "";}
string printVctPair2D(vector<vii>v){cout<<endl;for(ll i=0;i<sz(v);i++){cout<<i<<": ";for(ll j=0;j<sz(v[i]);j++)cout<<v[i][j].F<<":"<<v[i][j].S<<" ";cout<<endl;}return "";}
void check(ll n){cout<<"CHECKPOINT "<<n<<"\n\n";}
 
const ll dx[8]={1,-1,0,0,1,1,-1,-1}, dy[8]={0,0,1,-1,1,-1,1,-1};
 
void yesno(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
ll charToInt(char c){ return (ll)c-48; }
char intToChar(ll n){ return (char)n+48; }
 
bool debug = false;
 
void printMatrix(string s, ll a[2][2]){
	if (debug){
		cout<<s<<": matrix:"<<endl;
	    for (ll i = 0;i<2; i++){
	        for (ll j = 0; j<2; j++)
	            cout<<a[i][j]<<" ";
	        cout<<endl;
	    }
	}
}
 
void initMatrix(ll arr[2][2]){
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;
}
 
void multiMatrix(ll a[2][2], ll b[2][2], bool mod){
	ll tA[2][2], tB[2][2];
 
	tA[0][0] = a[0][0];
	tA[0][1] = a[0][1];
	tA[1][0] = a[1][0];
	tA[1][1] = a[1][1];
 
	tB[0][0] = b[0][0];
	tB[0][1] = b[0][1];
	tB[1][0] = b[1][0];
	tB[1][1] = b[1][1];
 
	if (!mod){
		a[0][0] = tA[0][0] * tB[0][0] + tA[0][1] * tB[1][0];
	    a[0][1] = tA[0][0] * tB[0][1] + tA[0][1] * tB[1][1];
	    a[1][0] = tA[1][0] * tB[0][0] + tA[1][1] * tB[1][0];
	    a[1][1] = tA[1][0] * tB[0][1] + tA[1][1] * tB[1][1];
	}
	else{
		a[0][0] = tA[0][0] * tB[0][0] % MOD + tA[0][1] * tB[1][0] % MOD;
	    a[0][1] = tA[0][0] * tB[0][1] % MOD + tA[0][1] * tB[1][1] % MOD;
	    a[1][0] = tA[1][0] * tB[0][0] % MOD + tA[1][1] * tB[1][0] % MOD;
	    a[1][1] = tA[1][0] * tB[0][1] % MOD + tA[1][1] * tB[1][1] % MOD;
	}
}
 
ll calcFib(ll n, bool mod){
	if (n == 0) return 0;
	ll ans[2][2];
	ll cur[2][2];
 
	initMatrix(ans);
	initMatrix(cur);
 
	n-=2;
	while (n > 0){
		printMatrix("ans",ans);
		printMatrix("cur",cur);
 
		if (n%2)
			multiMatrix(ans, cur, mod);
		multiMatrix(cur, cur, mod);
		n/=2;
	}
 
	printMatrix("ans", ans);
	printMatrix("cur", cur);
 
	return ans[0][0] % MOD;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	ll n;

	cout<<"\tFINDING THE Nth FIBONACCI NUMBER IN LOGARITHMIC TIME"<<endl<<endl;
	while (true){
		cout<<"Enter the value of N: ";
		cin>>n;
		if (n < 93){
			if (n < 0)
				n = 0;
			cout<<n<<"th Fibonacci: "<<calcFib(n,false)<<endl;
		}
		else{
			cout<<"(MODULO) "<<n<<"th Fibonacci: "<<calcFib(n,true)<<endl;
		}
		cout<<endl;
	}

	return 0;
}
 
 
/*
 Fib(10) = 55
*/
 
 
 
 
 

