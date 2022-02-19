#include <iostream>

using namespace std;

int search(int arr[], int low, int high, int key){
    int mid = (low+high) >> 1;
    if(arr[mid] == key){
        return mid;
    }

    // this case is added for low+1 == high
    if(low==mid && (arr[mid]!=key || arr[mid+1]!=key)){
        return -1;
    }

    if(arr[low] < arr[mid]) {
        // left side sorted
        if(key < arr[mid]){
            return search(arr, low, mid, key);
        } else {
            return search(arr, mid, high, key);
        }
    } else {
        // right side sorted
        if(key > arr[mid]){
            return search(arr, mid, high, key);
        } else {
            return search(arr, low, mid, key);
        }
    }

    return -1;
}

int main(){
    int input[] = { 4, 5, 6, 7, 8, 9, 1, 2 };
    int n = sizeof(input) / sizeof(input[0]);

    int key = 7;
    int index = search(input, 0, n-1, key);

    if (index != -1){
        cout << "Key found at Index: " << index << endl;
    } else {
        cout << "Key is not found in the array!" << endl;
    }

    return 0;
}

