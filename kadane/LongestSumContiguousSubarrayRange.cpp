#include <climits>
#include <iostream>

using namespace std;

void findMaximumSubArraySum(int arr[], int n){
    int maxSoFar = INT_MIN;
    int curr_max = 0;

    int start=0, finish;
    for(int i=0; i<n; i++ ){
        curr_max += arr[i];
        if (maxSoFar < curr_max){
            maxSoFar = curr_max;
            finish = i;
        }
        if (curr_max < 0){
            curr_max = 0;
            start = i + 1;
        }
    }

    cout<<"Maximum Subarray Sum ["<<start<<"-"<<finish<<"] = "<<maxSoFar;
}

int main(){
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    findMaximumSubArraySum(arr, n);

    return 0;
}

