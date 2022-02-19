#include <climits>
#include <iostream>

using namespace std;

void maxLeftSubArraySum(int arr[], int n, int sum[]){
    sum[0] = arr[0];
    int curr_max = arr[0];
    int maxSoFar = arr[0];
    for(int i=1; i<n; i++){
        curr_max = max(arr[i], curr_max+arr[i]);
        maxSoFar = max(maxSoFar, curr_max);
        sum[i] = maxSoFar;
    }
}

void minLeftSubArraySum(int arr[], int n, int sum[]){
    sum[0] = arr[0];
    int curr_min = arr[0];
    int minSoFar = arr[0];
    for(int i=1; i<n; i++){
        curr_min = min(arr[i], curr_min+arr[i]);
        minSoFar = min(minSoFar, curr_min);
        sum[i] = minSoFar;
    }
}

void maxRightSubArraySum(int arr[], int n, int sum[]){
    sum[n-1] = arr[n-1];
    int curr_max = arr[n-1];
    int maxSoFar = arr[n-1];
    for(int i=n-2; i>=0; i--){
        curr_max = max(arr[i], curr_max+arr[i]);
        maxSoFar = max(maxSoFar, curr_max);
        sum[i] = maxSoFar;
    }
}

void minRightSubArraySum(int arr[], int n, int sum[]){
    sum[n-1] = arr[n-1];
    int curr_min = arr[n-1];
    int minSoFar = arr[n-1];
    for(int i=n-2; i>=0; i--){
        curr_min = min(arr[i], curr_min+arr[i]);
        minSoFar = min(minSoFar, curr_min);
        sum[i] = minSoFar;
    }
}

int findMaxAbsDiff(int arr[], int n){
    int maxLeft[n];
    maxLeftSubArraySum(arr, n, maxLeft);

    int minLeft[n];
    minLeftSubArraySum(arr, n, minLeft);

    int maxRight[n];
    maxRightSubArraySum(arr, n, maxRight);

    int minRight[n];
    minRightSubArraySum(arr, n, minRight);

    int maxAbsDiff = INT_MIN;
    for(int i=0; i<n; i++){
        int diff = max(abs(maxLeft[i] - minRight[i+1]), abs(minLeft[i] - maxRight[i+1]));
        if (diff > maxAbsDiff){
            maxAbsDiff = diff;
        }
    }
    return maxAbsDiff;
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    cout<<"Maximum absolute difference = "<<findMaxAbsDiff(a, n);

    return 0;
}

