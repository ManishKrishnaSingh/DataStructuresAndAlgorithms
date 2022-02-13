#include <iostream>

using namespace std;

int sumBitDifferences(int arr[], int n){
    int bitcount[32] = {0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<32; j++){
            if(arr[i] & (1<<j)){
                bitcount[j]++;
            }
        }
    }

    int sumBitDiff = 0;
    for(int i=0; i<32; i++){
        sumBitDiff += (bitcount[i]*(n-bitcount[i]))*2;
    }

    return sumBitDiff;
}

int main(){
    int arr[] = { 1, 3, 5 };
    int n = sizeof arr / sizeof arr[0];
    int sumBitDiff = sumBitDifferences(arr, n);
    cout<<"Sum [Bit Difference] = "<<sumBitDiff;
    return 0;
}

