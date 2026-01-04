
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
 
using namespace std;
 
#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"
 
#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back
 
#define inf 1e6
#define INF 1e9
#define MOD 1000000007
 
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    ll a = 9;   //1001
    ll b = 7;   //0111
    
    cout<<"Values: "<<endl;
    cout<<"a: "<<a<<" (1001)"<<endl;
    cout<<"b: "<<b<<" (0111)"<<endl;
    cout<<endl;
    
    cout<<"AND: a & b: "<<(a & b)<<endl;
    cout<<"OR:  a | b: "<<(a | b)<<endl;
    cout<<"XOR: a ^ b: "<<(a ^ b)<<endl;
    cout<<"SHIFT: a << 1: "<<(a<<1)<<endl;
    cout<<"SHIFT: a >> 1: "<<(a>>1)<<endl;
    cout<<"COMPLEMENT: ~ b: "<<(~b)<<endl;
    cout<<"COMPLEMENT: ~ (llu)b: "<<(~(llu)b)<<endl;
    cout<<endl;
    
	return 0;
}

/*
BITWISE OPERATION NOTES:
    - XOR:
        1) a ^ a = 0
        2) a ^ 0 = a
        3) (a^b)^c = (a^c)^b
    -OR:
        1) a | a = a
        2) a | 0 = a
    -AND:
        1) a & 0 = 0
        2) a & 1 = a
    -SHIFT:
        1) a = a << b  ==  a *= pow(2,b)
        2) a = a << b  ==  a /= pow(2,b)
    -COMPLEMENT:
        1) Flips all bits (NOT GATE)
        2) Use on unsigned int to find max integer quickly
        3) ~a = -a-1 (where a is unsigned)
*/  

 
 
 
 