#include <climits>
#include <iostream>

using namespace std;

int maxNonNegativeSubArraySum(int arr[], int n){
    int result = INT_MIN;

    int sum = 0;

    int i=0;
    while (i < n){
        while (i < n && arr[i] < 0){
            i++; continue;
        }

        while (i < n && arr[i] >= 0){
            sum += arr[i++];
        }

        result = max(result, sum);
        sum = 0; //reset curr sum
    }

    return result;
}

int main(){
    int arr[] = {1, 4, -3, 9, 5, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "MaxNonNegativeSubArraySum = " << maxNonNegativeSubArraySum(arr, n)<<endl;

    return 0;
}

