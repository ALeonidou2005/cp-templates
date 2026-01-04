#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define sz(x) (ll)x.size()
#define pb push_back
#define MID ((l+r)/2)
#define F first
#define S second
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define dbg2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<endl;
#define inf 1e9
#define MOD 1000000007

typedef vector <ll> vi;
typedef pair <ll,ll> ii;
typedef vector <ii> vii;
typedef pair <ll,ii> iii;
typedef vector <iii> viii;

void printVct(vi &v){
    for (ll i=0; i<sz(v); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

ll mpow(ll a, ll b, ll mod){
    if (b == 0) return 1;
    if (b%2) return (a * mpow((a*a)%mod,b/2,mod)) % mod;
    return mpow((a*a)%mod,b/2,mod) % mod;
}

int main(){

    ll x, y;
    cin>>x>>y;
    dbg(mpow(x,y,MOD));

    return 0;
}

/*
45 12345
=> 58012576

*/