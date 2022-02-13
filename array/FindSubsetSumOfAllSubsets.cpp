#include <iostream>

using namespace std;

void printSumOfSubsets(int arr[], int n){
    int sumOfSubsets;
    for(int i=0; i<(1<<n); i++){
        sumOfSubsets = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                sumOfSubsets += arr[j];
            }
        }
        cout<<sumOfSubsets<<" ";
    }
}

int main(){
    int arr[] = { 5, 4, 3 };
    int n = sizeof(arr)/sizeof(int);

    printSumOfSubsets(arr, n);

    return 0;
}

