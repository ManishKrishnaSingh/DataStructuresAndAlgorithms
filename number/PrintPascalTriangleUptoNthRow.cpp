#include <iostream>

using namespace std;

//nCr = nCr-1 * (n-r+1) / r;
void pascalTriangeRow(int n){
    int curr;
    int prev = 1;
    cout<<prev<<" ";
    for(int i=1; i<=n; i++) {
        int curr = prev*(n-i+1)/i;
        cout<<curr<<" ";
        prev = curr;
    }
    cout<<endl;
}

void printPascalTriange(int n){
    for(int r=0; r<n; r++){
        pascalTriangeRow(r);
    }
}

int main(){
    printPascalTriange(10);
    return 0;
}

