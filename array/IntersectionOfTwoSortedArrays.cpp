#include <iostream>

using namespace std;

void findIntersections(int arr1[], int arr2[], int m, int n){
    int i=0, j=0;
    cout<<"Intersections:";
    while(i < m && j < n){
        if(arr1[i] == arr2[j]){
            cout<<" "<<arr1[i];
            i++; j++;
        } else if(arr1[i] < arr2[j]){
            i++;
        } else {
            j++;
        }
    }
}

int main(){
    int arr1[] = {2, 3, 5, 7};
    int arr2[] = {1, 2, 4, 5, 6};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    findIntersections(arr1, arr2, m, n);

    return 0;
}

