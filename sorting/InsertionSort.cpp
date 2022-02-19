#include <iostream>

using namespace std;

void insertionSort(int arr[], int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key = arr[i];

        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n){
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(int);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

