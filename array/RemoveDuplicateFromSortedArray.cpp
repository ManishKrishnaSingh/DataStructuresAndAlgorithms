#include <iostream>

using namespace std;

void removeDuplicateElements(int arr[], int n){
    int uniqueIndex=0;
    cout<<" "<<arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] != arr[uniqueIndex]){
            uniqueIndex = i;
            cout<<" "<<arr[i];
        }
    }
}

int main(){
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unique Elements:";
    removeDuplicateElements(arr, n);

    return 0;
}

