#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void maximizeArray(int arr1[], int arr2[], int n){
    int arr3[2*n], k=0;
    for(int i=0; i<n; i++){
        arr3[k++] = arr1[i];
    }
    for(int i=0; i<n; i++){
        arr3[k++] = arr2[i];
    }

    unordered_set<int> hash;
    sort(arr3, arr3+2*n, greater<int>());

    int i = 0;
    while(hash.size() != n && i<2*n) {
        if (hash.find(arr3[i]) == hash.end()){
            hash.insert(arr3[i]);
        }
        i++;
    }

    int idx = 0;
    for(int i=0; i<n; i++) {
        if (hash.find(arr2[i]) != hash.end()) {
            arr3[idx++] = arr2[i];
            hash.erase(arr2[i]);
        }
    }
    for(int i=0; i<n; i++) {
        if (hash.find(arr1[i]) != hash.end()) {
            arr3[idx++] = arr1[i];
            hash.erase(arr1[i]);
        }
    }

    for(int i=0; i<n; i++){
        arr1[i] = arr3[i];
    }
}

void PrintMaximizedArray(int arr[], int n){
    cout<<"Maximized Array:";
    for (int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
}

int main(){
    int arr1[] = { 7, 4, 8, 0, 1 };
    int arr2[] = { 9, 7, 2, 3, 6 };
    int n = sizeof(arr1)/sizeof(int);

    maximizeArray(arr1, arr2, n);

    PrintMaximizedArray(arr1, n);

    return 0;
}

