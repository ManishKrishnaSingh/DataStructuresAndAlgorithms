#include <iostream>

using namespace std;

int maxSubArraySum(int arr[], int n){
    int maxSoFar = arr[0];
    int currSum  = arr[0];

    for(int i=1; i<n; i++){
        currSum += arr[i];

        if(maxSoFar < currSum){
            maxSoFar = currSum;
        }

        if(currSum < 0){
            currSum = 0;
        }
    }

    return maxSoFar;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Sum [Largest SubArray] = "<<maxSubArraySum(arr, n);

    return 0;
}

