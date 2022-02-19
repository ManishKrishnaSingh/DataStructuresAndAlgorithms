#include <iostream>

using namespace std;

int findMaxSubArraySum(int arr[], int n){
    int maxSoFar = arr[0];
    int curr_sum = arr[0];
    for(int i=1; i<n; i++){
        curr_sum = max(arr[i], curr_sum+arr[i]);
        maxSoFar = max(curr_sum, maxSoFar);
    }
    return maxSoFar;
}

int main(){
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxSum = findMaxSubArraySum(arr, n);
    cout<<"Maximum Subarray Sum = "<<maxSum<<endl;
    return 0;
}

