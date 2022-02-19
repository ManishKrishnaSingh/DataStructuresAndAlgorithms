#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high){
    int idxLeft  = mid-low+1;
    int idxRight = high-mid;

    int *left  = new int[idxLeft];
    for(int i=0; i<idxLeft; i++){
        left[i] = arr[low+i];
    }

    int *right = new int[idxRight];
    for(int j=0; j<idxRight; j++){
        right[j] = arr[mid+1+j];
    }

    int i=0, j=0, index=low;
    while(i<idxLeft && j<idxRight) {
        if(left[i] <= right[j]) {
            arr[index++] = left[i++];
        } else {
            arr[index++] = right[j++];
        }
    }

    while(i<idxLeft){
        arr[index++] = left[i++];
    }
    while(j<idxRight){
        arr[index++] = right[j++];
    }
}

void mergeSort(int array[], int low, int high){
    if(low < high){
        int mid = (low+high) >> 1;
        mergeSort(array, low, mid);
        mergeSort(array, mid+1, high);
        merge(array, low, mid, high);
    }
}

void viewArray(int arr[], int n){
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    viewArray(arr, n);

    return 0;
}

