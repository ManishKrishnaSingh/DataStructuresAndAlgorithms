#include <iostream>

using namespace std;

int findPivot(int arr[], int low, int high){
    int mid = (low+high) >> 1;
    if(arr[mid] > arr[mid+1]){
        return mid;
    }

    if(arr[low] < arr[mid]) {
        // left side sorted
        return findPivot(arr, mid, high);
    } else {
        // right side sorted
        return findPivot(arr, low, mid);
    }

    return -1;
}

int main(){
    int input[] = { 4, 5, 6, 7, 8, 9, 1, 2 };
    int n = sizeof(input) / sizeof(input[0]);

    int key = 7;
    int index = findPivot(input, 0, n-1);
    cout << "Pivot Index = "<<index<<endl;

    return 0;
}

