#include <bits/stdc++.h>

using namespace std;

int rcOptimalStrategy(int arr[], int left, int right)
{
    if(left > right)
    {
        return 0;
    }

    int maxLeft  = arr[left]  + min(rcOptimalStrategy(arr, left+2, right), rcOptimalStrategy(arr, left+1, right-1));
    int maxRight = arr[right] + min(rcOptimalStrategy(arr, left+1, right-1), rcOptimalStrategy(arr, left, right-2));

    return max(maxLeft, maxRight);
}

int dpOptimalStrategy(int arr[], int left, int right, vector<vector<int>>& dp)
{
    if(left > right)
    {
        return 0;
    }

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int maxLeft  = arr[left]  + min(dpOptimalStrategy(arr, left+2, right, dp), dpOptimalStrategy(arr, left+1, right-1, dp));
    int maxRight = arr[right] + min(dpOptimalStrategy(arr, left+1, right-1, dp), dpOptimalStrategy(arr, left, right-2, dp));

    return dp[left][right] = max(maxLeft, maxRight);
}

int dpOptimalStrategy(int arr[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return dpOptimalStrategy(arr, 0, n-1, dp);
}

int main()
{
    int arr[] = { 8, 15, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Value [Optimal Strategy] = " <<rcOptimalStrategy(arr, 0, n-1)<<endl;
    cout<<"Value [Optimal Strategy] = " <<dpOptimalStrategy(arr, n)<<endl;

    return 0;
}

/************************
Recursive Method:
Time Complexity  : O(2^N)
Space Complexity : O(N)

Dynamic Programming:
Time Complexity  : O(N^2)
Space Complexity : O(N^2)
*************************/