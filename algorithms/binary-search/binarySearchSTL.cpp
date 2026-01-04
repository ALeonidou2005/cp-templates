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

/*

GOALS:
LowerBound => Get Value, Get Index
UpperBound => Get Value, Get Index
Search => true or false
Count => Get Count

LIMITATIONS:
*Only for Vectors

TIME COMPLEXITIES:
BS: O(log(n))
SORT: O(n * log(n))

*/

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n,k,x;
	vi v;
	cin>>n;
	for (ll i = 0; i<n; i++){
		cin>>x;
		v.pb(x);
	}
	cin>>k;

    sortVct(v);

    cout<<endl<<"Sorted Vector: "<<printVct(v,1)<<endl;
  
    vi::iterator low, high;
    ll lowIndex, highIndex;
    
    //Lower Bound (values < k)	O(log(n))
    low = lower_bound(all(v), k);
    lowIndex = low-v.begin()-1;
    cout<<"Lower Bound Index: "<<lowIndex<<endl;
    cout<<"Lower Bound Value: "<<v[lowIndex]<<endl;
    if (lowIndex == -1) cout<<" ** No Values Under "<<k<<endl;
    cout<<endl;
  
  	//Upper Bound (values > k)  O(log(n))
    high = upper_bound(all(v), k);
    highIndex = high-v.begin();
    cout<<"Upper Bound Index: "<<highIndex<<endl;
    cout<<"Upper Bound Value: "<<v[highIndex]<<endl;
    if (highIndex == sz(v)) cout<<" ** No Values Over "<<k<<endl;
    cout<<endl;

    //Search (k)  O(log(n))
    bool found = binary_search(all(v), k);
    if (found) cout<<"Binary Search: "<<k<<" => FOUND"<<endl;
    else cout<<"Binary Search: "<<k<<" => NOT FOUND"<<endl;
    cout<<endl;

    //Count (k)   O(2*log(n))
    vi::iterator low2;
    ll lowIndex2;
    low2 = lower_bound(low, v.end(), k+1);
    lowIndex2 = low2 - v.begin() - 1;
    cout<<"Count ("<<k<<"):  "<<lowIndex2-lowIndex<<endl;

	return 0;
}

/*

TEST INPUT:

7
10 20 30 30 30 40 50
0

10
3 4 9 8 2 5 1 8 5 3
4

5
8 2 2 3 1
3

5
1 2 3 4 5
1

4
8 8 8 8
8

6
8 8 8 9 1 3
5

*/

































