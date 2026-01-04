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

#define N 200000
#define MID ((l+r)/2)

/*
Segment Tree Description:
• Type: Sum
• Query Any Range
• Update single value
*/

ll arr[N+1],n,q;

struct node{
	node *L, *R;
	ll val;

	//build the tree
	void build(ll l = 1, ll r = n){
		if (l == r){
			val = arr[r];
		}
		else{
			L = new node;
			R = new node;

			L -> build(l, MID);
			R -> build(MID+1, r);

			val = L->val + R->val;
		}
	}

	//query a range in the tree
	ll query(ll tl, ll tr, ll l = 1, ll r = n){
		if (tl <= l && tr >= r) return val;
		else if (tl>r || tr<l) return 0;
		else return L->query(tl,tr,l,MID) + R->query(tl,tr,MID+1,r);
	}

	//update a single node in the tree
	void update(ll pos, ll dif, ll l = 1, ll r = n){
		if (l == r && l == pos) val += dif;
		else if (l > pos || r < pos) return;
		else{
			val += dif;
			L->update(pos, dif, l, MID);
			R->update(pos, dif, MID+1, r);
		}
	}

	//traverse tree for debugging (using bfs)
	void traverse(){
		cout<<endl;
		typedef pair<node, ll> nl;
		queue <nl> q;
		nl cur;
		ll level = 0;
		q.push(nl(*this, 1));
		while (!q.empty()){
			cur = q.front();
			q.pop();
			if (cur.S != level){
				level = cur.S;
				cout<<endl<<"l:"<<level<<"  ";
			}
			cout<<cur.F.val<<" ";
			if (cur.F.L != nullptr)	q.push(nl(*cur.F.L, level+1));
			if (cur.F.R != nullptr)	q.push(nl(*cur.F.R, level+1));
		}
		cout<<endl<<endl;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>q;

	for (ll i = 1; i<=n; i++)
		cin>>arr[i];

	node root;
	root.build();
	ll m, a,b;

	root.traverse();

	while (q--){
		cin>>m>>a>>b;
		if (m==1){
			root.update(a, b-arr[a]);
			arr[a] = b;		//updating original array
		}
		else{
			cout<<root.query(a,b)<<endl;
		}
		//root.traverse();
	}
	
	return 0;
}


/*
10 5
3 2 4 5 1 1 5 3 7 2
2 1 4
2 5 6
1 3 1
2 1 4
1 10 15

8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
*/

































