#include <iostream>
using namespace std;

int gcd (int x, int y){
    if (y == 0)
        return x;
    return gcd(y,x%y);
}

int lcm (int x, int y){
    return y / gcd(x,y) * x;
}

int main(){
    int a, b;
    cout<<"Enter two integers: ";
    cin >> a >> b;
    
    cout<<"Greatest Common Denomenator (gcd) is: " << gcd(a,b) << endl;
    cout<<"Least Common Multiple (lcm) is: " << lcm(a,b) << endl;
return 0;
}
