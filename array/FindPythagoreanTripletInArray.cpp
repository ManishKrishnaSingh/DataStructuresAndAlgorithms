#include <iostream>
#include <algorithm>

using namespace std;

bool hasPythagoreanTriplet(int arr[], int n){
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        arr[i] = arr[i]*arr[i];
    }

    for(int i=n-1; i>=0; i--){
        int left=0;
        int right = i-1;
        while(left < right){
            if(arr[left]+arr[right] == arr[i]){
                return true;
            }
            (arr[left]+arr[right]) < arr[i] ? left++ : right--;
        }
    }

    return false;
}

int main(){
    int arr[] = { 3, 1, 4, 6, 5 };
    int n = sizeof(arr)/sizeof(int);

    bool result = hasPythagoreanTriplet(arr,n);
    cout<<"Has Pythagorean Triplet = "<<boolalpha<<result;

    return 0;
}

