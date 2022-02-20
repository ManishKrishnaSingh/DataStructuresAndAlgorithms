#include <iostream>
#include <algorithm>

using namespace std;

void findTriplet(int arr[], int n, int sumTarget){
    if(n>=3){
        sort(arr, arr+n);
        for(int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;
            while(left < right){
                int sum = arr[i]+arr[left]+arr[right];
                if(sum == sumTarget){
                    cout<<"Solution: ["<<arr[i]<<"+"<<arr[left]<<"+"<<arr[right]<<"]"<<endl;
                    return;
                } else if(sum <sumTarget){
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    cout<<"No Solution!"<<std::endl;
}

int main(){
    int sumTarget = 22;
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    findTriplet(arr, n, sumTarget);

    return 0;
}

