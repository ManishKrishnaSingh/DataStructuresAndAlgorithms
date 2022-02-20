#include <bits/stdc++.h>

using namespace std;

int findElementThatAppearsOnce(int arr[], int n){
    int number = 0;

    int bitsum[32] = {0};
    for(int i=0; i<32; i++) {
        int x = (1<<i);
        for(int j=0; j<n; j++) {
            if (arr[j] & x){
                bitsum[i]++;
            }
		}
    }

    for(int i=0; i<32; i++) {
        bitsum[i] = bitsum[i]%3;
        if(bitsum[i]){
            number = number | (1<<i);
        }
    }
    
    return number;
}

int main(){
    int arr[] = {7,4,8,7,2,7,4,2,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int num=findElementThatAppearsOnce(arr, n);
    cout<<"Number that appreared once = "<<num;

    return 0;
}

