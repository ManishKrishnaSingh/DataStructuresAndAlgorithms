#include <bits/stdc++.h>

using namespace std;

int findMissingNumber(int arr[], int n){
    int xorOfArray = arr[0];
    for(int i=1; i<n; i++){
        xorOfArray = xorOfArray ^ arr[i];
    }

    int xorOfRange = 0;
    for(int i=1; i<=n+1; i++){
        xorOfRange = xorOfRange ^ i;
    }

    return (xorOfArray ^ xorOfRange);
}

int main(){
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);

    int number = findMissingNumber(arr, n);
    cout<<"Missing Number = "<<number<<endl;

    return 0;
}

