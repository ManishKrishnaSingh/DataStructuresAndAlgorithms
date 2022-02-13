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

int lcm(int input[], int n){
    int lcm = input[0];
    for(int i=1; i<n; i++){
        lcm = (lcm/gcd(lcm, input[i])) * input[i];
    }
    return lcm;
}

int main(){
    int input[] = {14, 42, 70};
    int n = sizeof(input)/sizeof(int);
    cout<<"LCM[ARRAY] = "<<lcm(input, n)<<endl;
    return 0;
}

