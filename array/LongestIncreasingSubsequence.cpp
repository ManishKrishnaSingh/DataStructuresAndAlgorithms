#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int findLongestIncreasingSubsequence(int arr[], int n){
    if (n == 0){
        return 0;
    }

    vector<int> Tail(n);

    int length = 1;
    Tail[0] = arr[0];

    for (int i=1; i<n; i++) {
        auto it = lower_bound(Tail.begin(), Tail.begin()+length, arr[i]);
        if (it == Tail.begin() + length){
            Tail[length++] = arr[i];
        } else {
            *it = arr[i];
        }
    }
    return length;
}

int dpLongestIncreasingSubsequence(int arr[], int n){
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && dp[i]<(dp[j]+1)){
                dp[i] = dp[j]+1;
            }
        }
    }
    int maxLength = INT_MIN;
    for(int i=0; i<n; i++){
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int lisLength = findLongestIncreasingSubsequence(arr, n);
    cout <<"Length [Longest Increasing Subsequence] = "<<lisLength<<endl;

    int dpLisLen = dpLongestIncreasingSubsequence(arr, n);
    cout <<"Length [Longest Increasing Subsequence] = "<<dpLisLen<<endl;

    return 0;
}

