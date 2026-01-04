//CSES: https://cses.fi/problemset/task/1688/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (ll)x.size()
#define F first
#define S second 
#define pb push_back
#define INF 1000000000000000000

typedef vector <ll> vi;
typedef pair<ll,ll> ii;
typedef vector <ii> vii;
typedef pair <ll,ii> iii;
typedef vector <iii> viii;

#define dbg(x) cout<<#x<<": "<<x<<endl;
#define dbg2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<endl;

void printVct(vi &v){
    for (ll i =0; i<sz(v); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

#define N 200000
#define LOGN 20

vector <vi> adj;
ll dp[N][LOGN];
vi depth;

void binary_lifting(ll u, ll p){
    if (u == 0) depth[u] = 0;
    else depth[u] = depth[p] + 1;

    dp[u][0] = p;
    for (ll i =1; i<LOGN; i++){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }

    for (ll i =0; i<sz(adj[u]); i++){
        ll c = adj[u][i];
        if (c != p){
            binary_lifting(c, u);
        }
    }
}

ll kth_ancestor(ll x, ll d){
    ll p = 0;
    while (d){
        if (d & 1){
            x = dp[x][p];
        }
        d >>= 1;
        p++;
    }
    return x;
}

ll lca(ll a, ll b){
    if (depth[a] > depth[b]) swap(a,b);
    b = kth_ancestor(b, depth[b] - depth[a]);
    if (a == b) return a;
    for (ll i = LOGN-1; i>=0; i--){
        if (dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main(){
    ll n, q;
    cin>>n>>q;

    adj.assign(n, vi());
    depth.assign(n, 0);
    ll x;
    for (ll i=1; i<n; i++){
        cin>>x; x--;
        adj[i].pb(x);
        adj[x].pb(i);
    }

    for (ll i=0; i<N; i++){
        for (ll j =0; j<LOGN; j++){
            dp[i][j] = 0;
        }
    }

    binary_lifting(0,0);

    while (q--){
        ll a,b;
        cin>>a>>b; a--,b--;
        ll ans = lca(a,b);
        cout<<ans+1<<endl;
    }
}

/*
5 3
1 1 3 3
4 5
2 5
1 4

*/