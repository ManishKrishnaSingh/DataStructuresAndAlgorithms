#include <iostream>

using namespace std;

int findMajority(int arr[], int n){
    int count = 1;
    int candidate = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] == candidate){
            count++;
        } else {
            count--;
        }
        if(count == 0){
            count = 1;
            candidate = arr[i];
        }
    }

    count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == candidate){
            count++;

            if(count>n/2){
                return candidate;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {4, 3, 4, 4, 4, 2};
    int n = sizeof(arr)/sizeof(int);

    int result = findMajority(arr, n);
    cout<<"Majority Element = "<<result;

    return 0;
}

