#include <bits/stdc++.h>

using namespace std;

pair<int,int> findFirstAndLastIndicesOfElement(int arr[], int n, int num){
    if(n >= 2){
        int low=0, mid, high=n-1;

        while(low <= high){
            mid=(low+high)>>1;
            // element found
            if(arr[mid] == num){
                int left,right;

                left=right=mid;
                //update to the leftmost index
                while(left > 0 and arr[left-1] == arr[mid]){
                    left--;
                }
                //update to the rightmost index
                while(right < n-1 and arr[right+1] == arr[mid]){
                    right++;
                }

                if(left != right){
                    return {left, right};
                }
            }

            //update low/high
            if(arr[mid] < num){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return {-1,-1};
}

int main() {
    int arr[] = {1,2,2,2,2,3,4,7,8,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    auto answer = findFirstAndLastIndicesOfElement(arr, n, 8);
    cout<<"Indices = ["<<answer.first<<","<<answer.second<<"]";

    return 0;
}