#include <iostream>
#include <string>

using namespace std;

#define ll long long
#define BASE 227
#define MOD 1000000007

ll hhash(string s, ll l = -1) {
	if (l == -1)
		l = s.size();
    ll h = 0;
	for (ll i = 0; i < l; i++)
    	h = (h * BASE + s[i]) % MOD;
    return h;
}

ll rabin_karp(string s, string t) {
    ll h1 = hhash(t), h2 = hhash(s, t.size());

    if (h1 == h2)
    	return 0;

    ll power = 1;
    for (ll i = 0; i < t.size(); i++)
    	power = (power * BASE) % MOD;

   	for (ll i = t.size(); i < s.size(); i++) {
   		h2 = (h2*BASE + s[i]) % MOD;
        h2 = (h2 - (power * s[i-t.size()] % MOD) + MOD) % MOD;
    	if (h1 == h2)
        	return i - (t.size() - 1);
   	}

   	return -1;
}

int main() {
	string s, t;
    cin>>s>>t;

    ll ans = rabin_karp(s, t);
    if(ans == -1)
    	cout<<"String not found"<<endl;
    else
    	cout<<"String \""<<t<<"\" found at position "<<ans<<endl;

   return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(n)

/*
Sample Cases: 

zzzzzzzzzzzzzbzazzzzzzzzzzzzczzz
zzzzbzazzzzzzzzz

dbzazzzzzzzzzzzzc
bzazzzzzzzzzzzzc

abcd
bc
*/

//Learned From: https://www.tutorialspoint.com/cplusplus-program-to-implement-rolling-hash






















