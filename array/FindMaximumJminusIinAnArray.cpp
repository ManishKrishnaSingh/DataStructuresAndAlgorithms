#include <climits>
#include <iostream>

using namespace std;

int maxIndexDiff(int arr[], int n){
    int maxDiff = INT_MIN;

    int minLeft[n];
    minLeft[0] = arr[0];
    for(int i=1; i<n; i++){
        minLeft[i] = min(arr[i], minLeft[i-1]);
    }

    int maxRight[n];
    maxRight[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        maxRight[i] = max(arr[i], maxRight[i+1]);
    }

    int i=0, j=0;
    while(i<n && j<n){
        if(minLeft[i] <= maxRight[j]){
            maxDiff = max(j-i, maxDiff); j++;
        } else {
            i++;
        }
    }

    return maxDiff;
}

int main(){
    int arr[]={9,2,3,4,5,6,7,8,18,0};
    int n = sizeof(arr) / sizeof(int);

    int maxDiff = maxIndexDiff(arr, n);
    cout<<"Maximum Difference = "<<maxDiff;

    return 0;
}

