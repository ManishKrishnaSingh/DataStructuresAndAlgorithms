#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    int a=14, b=35;

    cout<<"GCD["<<a<<","<<b<<"] = "<<gcd(a, b)<<endl;

    return 0;
}

