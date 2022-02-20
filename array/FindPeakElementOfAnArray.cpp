#include <iostream>

using namespace std;

int findPeak(int input[], int low, int high, int n){
    int mid = (low+high) >> 1;

    if((mid==0 || input[mid-1]<=input[mid]) && (mid==n-1 || input[mid]>=input[mid+1])){
        return mid;
    } else if(mid>0 && input[mid]<input[mid-1]){
        return findPeak(input, low, mid-1, n);
    } else {
        return findPeak(input, mid+1, high, n);
    }

    return -1;
}

int main(){
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(int);

    int idx  = findPeak(arr, 0, n-1, n);
    int peak = (idx==-1) ? -1 : arr[idx];
    cout << "Peak Element = "<<peak<<endl;

    return 0;
}

