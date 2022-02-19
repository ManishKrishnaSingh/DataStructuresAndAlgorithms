#include <iostream>

using namespace std;

void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void viewSortedArray(int arr[], int n){
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(int);

    selectionSort(arr, n);
    viewSortedArray(arr, n);

    return 0;
}

