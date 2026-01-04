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
#include <chrono>
#include <unistd.h>

using namespace std;
using namespace chrono;

#define ll long long
#define llu unsigned long long
#define ld long double
#define F first
#define S second
#define endl "\n"
#define sz(x) (ll)(x).size()
#define pb push_back
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;
high_resolution_clock::time_point start;
high_resolution_clock::time_point stop;
duration<ld> dur;
void timerStart(){
	start = std::chrono::high_resolution_clock::now();
}
void timerStop(){
	stop = std::chrono::high_resolution_clock::now();
	dur = duration_cast<std::chrono::microseconds>(stop - start);
}
ld timerDuration(){
	return dur.count();
	//NOTE: Duration is given in microsecond precision (μs)
}

#define T 6     //Test Repetitions

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout<<"\t\tSPEED TEST"<<endl;
	for (ll t = 1; t<=T; t++){
		cout<<endl<<"TEST RUN "<<t<<endl;
		timerStart();
		/*
			Enter code to be speed tested here...
		*/
		timerStop();
		cout<<"Time taken by test 1: "<<timerDuration()<<" μs"<<endl;
	}

	return 0;
}


/*
SPEED TEST RESULTS:


SPEED TEST CONCLUSIONS:


*/

































