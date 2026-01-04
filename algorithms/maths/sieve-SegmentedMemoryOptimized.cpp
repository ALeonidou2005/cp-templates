#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define ll long long
#define llu unsigned long long
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back

#define N 1000000

typedef vector <ll> vi;

bitset < N + 1 > numbers;
vi primes;
void sieve(){
    numbers.set();
    numbers[1] = 0;
    
    for (ll i = 2; i<N; i++){
        if (numbers[i] == 1){
            primes.pb(i);
            for (ll j = i*i; j<N; j+=i){
                numbers[j] = 0;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    system("clear");
    
    sieve();

    ll t;
    cin>>t;
    
    while (t--){
        ll l,r;
        cin>>l>>r;
        
        float tmpSqrt = sqrt(r);
        ll sqrtR = (ll)tmpSqrt;
        if (tmpSqrt != (float)sqrtR)
            sqrtR++;
        
        ll lastPrimeIndexInRange = 0;
        while (primes[lastPrimeIndexInRange] <= sqrtR)
            lastPrimeIndexInRange++;
        
        numbers.set();
        if (l == 1)
            numbers[0] = 0;
        
        for (llu i = 0; i<lastPrimeIndexInRange; i++){
            
            ll firstMulti = (l/primes[i]) * primes[i];
            if (firstMulti < l)
                firstMulti += primes[i];
            
            for (ll j = max(firstMulti, primes[i] * primes[i]); j<=r; j+= primes[i])
                numbers[j-l] = 0;
        }
        
        for (ll i = 0; i<r-l+1; i++)
            if (numbers[i] == 1)
                cout<<i + l<<endl;
        cout<<endl;
    }
    
	return 0;
}
