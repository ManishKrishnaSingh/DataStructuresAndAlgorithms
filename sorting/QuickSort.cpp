#include <iostream>

using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int i=low-1;
    for(int j=low; j<high; j++){
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSortArray(int arr[], int low, int high){
    if(low < high){
        int pi=partition(arr,low,high);
        quickSortArray(arr, low, pi-1);
        quickSortArray(arr, pi+1, high);
    }
}

void viewSortedArray(int arr[], int n){
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(int);

    quickSortArray(arr, 0, n-1);
    viewSortedArray(arr, n);

    return 0;
}

