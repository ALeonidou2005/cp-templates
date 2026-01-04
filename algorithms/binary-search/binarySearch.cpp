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

#define N 100000

/*
	Note:
	• x = array of numbers
	• n = length of the array
	• k = search key
	• returns "true" if the key is found, "false" otherwise
*/

//Time Complexity: O(log(n))
//Returns smallest index of the target's apperance, or -1 if the target is not found
ll search_classic(ll x[], ll n, ll k) {
    ll l = 0, r = n-1, m;
    while (l <= r) {
        m = (l+r)/2;
        if (x[m] == k) 
        	return m;
        if (x[m] < k) 
        	l = m+1; 
        else 
        	r = m-1;
    }
    return -1;
}


//Time Complexity: O(log(n))
//Returns largest index of the target's apperance, or -1 if the target is not found
ll search(ll x[], ll n, ll k) {
    ll p = 0;
    for (ll a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) 
        	p += a;
    }
    if (x[p] == k)
    	return p;
    return -1;
}


//Time Complexity: O(log(n))
//Returns number of appearances of the target
ll count(ll x[], ll n, ll k) {
    ll p = -1, q = -1;
    for (ll a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] < k) 
        	p += a;
		while (q+a < n && x[q+a] <= k) 
			q += a;
	}
	return q-p;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll arr[N+1];
	ll n;
	cin>>n;

	for (ll i = 0; i<n; i++)
		cin>>arr[i];

	sort(arr, arr+n);
	
	ll k = 8;
	cout<<endl<<"Sorted Array: "<<printArr(arr, n,1)<<endl;
	cout<<"Target: "<<k<<endl<<endl;

	cout<<"Search_Classic: "<<search_classic(arr, n, k)<<endl;

	cout<<"Search: "<<search(arr, n, k)<<endl;

	cout<<"Count: "<<count(arr, n, k)<<endl;
	
	return 0;
}

/*

TEST INPUT:

10
3 4 9 8 2 5 1 8 5 3

5
8 2 2 3 1

5
1 2 3 4 5

4
8 8 8 8

6
8 8 8 9 1 3

*/


/*
Good Binary Search Problem Links:
	• Multiplication Table: https://codeforces.com/contest/448/problem/D
	• 
	• 
*/































