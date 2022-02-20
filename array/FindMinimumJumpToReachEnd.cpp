#include <iostream>

using namespace std;

int minJumps(int arr[], int n){
    if(n <= 1){
        return 0;
    }

    if(arr[0]==0){
        return -1;
    }

    int noOfJumps = 1;
    int noOfSteps = arr[0];
    int maxReach  = arr[0];

    for(int i=1; i<n; i++){
        if(i==n-1){
            return noOfJumps;
        }
        maxReach = max(maxReach, i+arr[i]);
        noOfSteps--;
        if(noOfSteps == 0){
            noOfJumps++;
            if(i>=maxReach){
                return -1;
            }
            noOfSteps = maxReach - i;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    cout<<"Minimum no of jumps = "<<minJumps(arr, n);

    return 0;
}

