#include <climits>
#include <iostream>

using namespace std;

int maxDistance(int arr[], int n){
    int rightMax[n];
    rightMax[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(arr[i], rightMax[i+1]);
    }

    int result=INT_MIN;
    for(int i=0; i<n; i++){
        int diff = INT_MIN;
        int low=i+1, high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[i] <= rightMax[mid]){
                diff=max(diff, mid-i);
                low=mid+1;
            } else {
                high = mid-1;
            }
        }

        result = max(result, diff);
    }

    return result;
}

int main(){
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Maximum Distance = "<<maxDistance(arr, n);

    return 0;
}

