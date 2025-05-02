#include <bits/stdc++.h>

using namespace std;

void findUniquePairInArrayOfPairs(int arr[], int n){
    int xorOfArray = arr[0];
    for(int i = 1; i < n; i++){
        xorOfArray = xorOfArray^arr[i];
    }

    // rightmost set bit of xorOfArray
    int rightmostSetBit = xorOfArray & ~(xorOfArray-1);

    int x=0, y=0;//missing pair
    for(int i=0; i<n; i++){
        if (arr[i] & rightmostSetBit){
            x = x^arr[i];
        } else {
            y = y^arr[i];
        }
    }

    cout<<"Unique pair = ["<<x<<","<<y<<"]";
}

int main(){
    int arr[] = { 6,1,3,5,1,3,7,6 };
    int n = sizeof(arr)/sizeof(int);

    findUniquePairInArrayOfPairs(arr,n);

    return 0;
}

