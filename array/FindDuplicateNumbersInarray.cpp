#include <bits/stdc++.h>

using namespace std;

void findDuplicatesInTheArray(int arr[], int n){
    for(int i=0; i<n; i++) {
        arr[arr[i]%n] = arr[arr[i]%n] + n;
    }

    cout<<"Duplicates are:";
    for(int i=0; i<n; i++) {
        if(arr[i] >= n*2) {
            cout<<" "<<i;
        }
    }
}

int main(){
    int arr[] = { 0,4,3,2,7,8,2,3,1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    findDuplicatesInTheArray(arr, n);
    return 0;
}

