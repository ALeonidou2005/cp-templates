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

#define inf 1e6
#define INF 1e9
#define MOD 1000000007

typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

void yesno(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
ll charToInt(char c){ return (ll)c-48; }
char intToChar(ll n){ return (char)n+48; }


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll a;
	cin>>a;

	ll r = sqrt(a);

	for (ll i = 1; i<=r; i++){
		if (a % i == 0){
			cout<<a/i<<" "<<i<<endl;
		}
	}
	
	return 0;
}

//Time Complexity: O(sqrt(n))






























