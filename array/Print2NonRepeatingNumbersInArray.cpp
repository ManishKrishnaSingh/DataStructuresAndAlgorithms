#include <bits/stdc++.h>

using namespace std;

void PrintTwoNonRepeatingNumbers(int arr[], int n){
    int xorOfArray = arr[0];
    for(int i=1; i<n; i++){
        xorOfArray = xorOfArray ^ arr[i];
    }

    int rightMostSetBit =  xorOfArray & ~(xorOfArray-1);

    int x=0, y=0;
    for(int i=0; i<n; i++) {
        if (arr[i] & rightMostSetBit){
            x = x ^ arr[i];
        } else {
            y = y ^ arr[i];
        }
    }

    cout<<"Non-repeating Numbers = ["<<x<<","<<y<<"]";
}

int main(){
    int arr[] = {21,54,12,91,17,21,54,17};
    int n = sizeof(arr)/sizeof(int);
    PrintTwoNonRepeatingNumbers(arr, n);
    return 0;
}

