#include <iostream>

using namespace std;

int gcdUtil(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    return gcdUtil(b, a%b);
}

int gcd(int input[], int n){
    int gcd = input[0];
    for(int i=1; i<n; i++){
        gcd = gcdUtil(gcd, input[i]);
    }
    return gcd;
}

int main(){
    int input[] = {14, 42, 70};
    int n = sizeof(input)/sizeof(int);
    cout<<"HCF[ARRAY] = "<<gcd(input, n)<<endl;
    return 0;
}
