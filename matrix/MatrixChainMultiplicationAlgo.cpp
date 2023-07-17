#include <bits/stdc++.h>

using namespace std;

/***************************************************************************************
Matrix chain multiplication is an optimization problem concerning the most efficient way
to multiply the given seq of matrices. The problem is not actually to do multiplications,
but merely to decide the sequence of the matrix multiplications involved.

For example, for four matrices A, B, C, and D, there are five possible options:
((A*B)*C)*D   =   (A*(B*C))*D   =   (A*B)*(C*D)   =   A*((B*C)*D)   =   A*(B*(C*D))
****************************************************************************************/

int matrixChainMultiplication(int arr[], int left, int right, vector<vector<int>>& dp)
{
    if (left == right)
    {
        return 0;
    }

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    dp[left][right] = INT_MAX;

    int k, multiLeft, multiRight;
    for(k = left; k < right; k++)
    {
        multiLeft  = matrixChainMultiplication(arr, left, k, dp);
        multiRight = matrixChainMultiplication(arr, k+1, right, dp);

        dp[left][right] = min(dp[left][right], (multiLeft + multiRight + arr[left-1]*arr[k]*arr[right]));
    }

    return dp[left][right];
}

int findMinimuMatrixChainMultiplication(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n,-1));

    return matrixChainMultiplication(arr, 1, n-1, dp);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum multiplications = "<< findMinimuMatrixChainMultiplication(arr, n);

    return 0;
}

/************************
Time Complexity  : O(N^3)
Space Complexity : O(N^2)
*************************/