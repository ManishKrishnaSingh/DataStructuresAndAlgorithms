#include <iostream>

using namespace std;

void sort012(int arr[], int n){
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        switch(arr[mid]){
            case 0: swap(arr[low++],arr[mid++]); break;
            case 1: mid++; break;
            case 2: swap(arr[mid], arr[high--]); break;
        }
    }
}

void viewArray(int arr[], int n){
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);
    viewArray(arr, n);

    return 0;
}

