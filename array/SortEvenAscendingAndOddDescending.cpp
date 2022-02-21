#include <bits/stdc++.h>

using namespace std;

void sortEvenAscOddDesc(int arr[], int n){
    for(int i=0; i<n; i++){
        // odd numbers
        if (arr[i] & 1){
            arr[i] *= -1;
        }
    }

    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        if (arr[i] & 1){
            arr[i] *= -1;
        }
    }

    cout<<"Sorted Array:";
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

int main(){
    int arr[] = { 1, 3, 2, 7, 5, 4 };
    int n = sizeof(arr) / sizeof(int);
    
    sortEvenAscOddDesc(arr,n);//two way sort

    return 0;
}

