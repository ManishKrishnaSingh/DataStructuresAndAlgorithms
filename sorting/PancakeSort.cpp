#include <iostream>

using namespace std;

void reverse(int arr[], int index){
    int start = 0;
    while(start < index){
        swap(arr[start++], arr[index--]);
    }
}

int findMax(int arr[], int n){
    int maxIndex=0;
    for(int i=0; i<n; ++i){
        if (arr[i] > arr[maxIndex]){
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(int *arr, int n){
    for (int size=n; size>1; size--){
        int index = findMax(arr, size);
        if (index != size-1){
            reverse(arr, index);
            reverse(arr, size-1);
        }
    }
}

void viewSortedArray(int arr[], int n){
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {23,10,2,11,12,6,7};
    int n = sizeof(arr)/sizeof(int);

    pancakeSort(arr, n);
    viewSortedArray(arr, n);

    return 0;
}

