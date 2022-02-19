#include <iostream>

using namespace std;

int findTrappedRainWater(int arr[], int n){
    int left[n];
    left[0] = arr[0];
    for(int i=1; i<n; i++){
        left[i] = max(arr[i], left[i-1]);
    }

    int right[n];
    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(arr[i], right[i+1]);
    }

    int water = 0;
    for(int i=0; i<n; i++){
        water += min(left[i], right[i]) - arr[i];
    }

    return water;
}

int main(){
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Maximum Trapped Rain Water = "<<findTrappedRainWater(arr, n);

    return 0;
}

