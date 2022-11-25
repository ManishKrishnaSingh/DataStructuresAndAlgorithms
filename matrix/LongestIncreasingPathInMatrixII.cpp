#include <bits/stdc++.h>

using namespace std;

const int M = 4;
const int N = 4;

bool IsSafe(int i, int j)
{
    return (i>=0 and i<M and j>=0 and j<N);
}

int dfs(int mat[M][N], int dp[M][N], int i, int j)
{
    if(dp[i][j] == -1)
    {
        int left=0, right=0, up=0, down=0;
        if(IsSafe(i-1, j) and mat[i-1][j] > mat[i][j])
        {
            left = dfs(mat, dp, i-1, j);
        }
        if(IsSafe(i+1, j) and mat[i+1][j] > mat[i][j])
        {
            right = dfs(mat, dp, i+1, j);
        }
        if(IsSafe(i, j-1) and mat[i][j-1] > mat[i][j])
        {
            up = dfs(mat, dp, i, j-1);
        }
        if(IsSafe(i, j+1) and mat[i][j+1] > mat[i][j])
        {
            down = dfs(mat, dp, i, j+1);
        }

        dp[i][j] = 1 + max(left,max(right,max(up, down)));
    }
    return dp[i][j];
}

int findLongestIncreasingPath(int mat[M][N])
{
    int dp[M][N];
    memset(dp, -1, sizeof dp);

    int maxLength = 1;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(dp[i][j] == -1)
            {
                maxLength = max(maxLength, dfs(mat, dp, i, j));
            }
        }
    }
    return maxLength;
}

int main()
{
    int mat[M][N] = {
        { 1, 2, 3, 4 },
        { 2, 2, 3, 4 },
        { 3, 2, 3, 4 },
        { 4, 5, 6, 7 },
    };
    
    int maxLength = findLongestIncreasingPath(mat);
    cout<<"Longest Increasing Path => "<<maxLength;

    return 0;
}