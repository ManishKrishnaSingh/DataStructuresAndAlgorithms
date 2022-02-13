#include <bits/stdc++.h>

using namespace std;

void findClosestElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){
    int X, Y, Z;
    int diff = INT_MAX;

    int i=0, j=0, k=0;
    while(i < n1 && j < n2 && k < n3){
        int maxElement = max(arr1[i], max(arr2[j], arr3[k]));
        int minElement = min(arr1[i], min(arr2[j], arr3[k]));

        int curr = maxElement - minElement;
        if(curr < diff){
            X=arr1[i];
            Y=arr2[j];
            Z=arr3[k];
            diff = curr;
        }

	if(arr1[i] == minElement){
            i++;
        } else if(arr2[j] == minElement){
            j++;
        } else {
            k++;
        }
    }

    cout<<"Closest Elements: "<<X<<","<<Y<<","<<Z<<endl;
}

int main(){
    int arr1[] = {10, 12};
    int arr2[] = {1, 4, 10};
    int arr3[] = {2, 15, 20};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr1)/sizeof(arr3[0]);

    findClosestElements(arr1, arr2, arr3, n1, n2, n3);

    return 0;
}

