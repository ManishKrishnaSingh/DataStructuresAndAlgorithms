#include <iostream>

using namespace std;

// nCr = n!/r!(n-r)!
void nthRowPascalTriange(int n){
    n--;
    int curr;
    int prev=1;
    cout<<prev<<" ";

    for(int i=1; i<=n; i++){
        curr = prev*(n-i+1)/i;
        cout<<curr<<" ";
        prev = curr;
    }
    cout<<endl;
}

int main(){
    nthRowPascalTriange(10);
    return 0;
}

