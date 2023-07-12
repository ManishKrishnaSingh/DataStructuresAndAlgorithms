#include <bits/stdc++.h>

using namespace std;

int dpMinJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    int i, j;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(i <= j+arr[j] && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], 1+dp[j]);
            }
        }
    }

    return dp[n-1];
}


int opMinJumps(int arr[], int n)
{
    if(n <= 1)
    {
        return 0;
    }

    if(arr[0]==0)
    {
        return -1;
    }

    int noOfJumps = 1;
    int noOfSteps = arr[0];
    int maxReach  = arr[0];

    for(int i=1; i<n; i++)
    {
        if(i==n-1)
        {
            return noOfJumps;
        }

        maxReach = max(maxReach, i+arr[i]);

        noOfSteps--;
        if(noOfSteps == 0)
        {
            noOfJumps++;
            if(i>=maxReach)
            {
                return -1;
            }
            noOfSteps = maxReach - i;
        }
    }

    return -1;
}


int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    cout<<"Minimum Jumps = "<<dpMinJumps(arr, n)<<endl;
    cout<<"Minimum Jumps = "<<opMinJumps(arr, n)<<endl;

    return 0;
}

/*************************
Dynamic Programming:
Time Complexity  : O(N^2)
Space Complexity : O(N)

Optimized Approach:
Time Complexity  : O(N)
Space Complexity : O(1)
**************************/
