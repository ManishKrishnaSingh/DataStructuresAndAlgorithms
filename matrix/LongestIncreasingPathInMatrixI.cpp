#include <cstring>
#include <iostream>

const int N = 4;

using namespace std;

int dfs(int dp[N+1][N+1], int mat[N][N], int x, int y)
{
    if (dp[x][y] == -1)
    {
        int right = 0, down = 0;

        if ((x+1) < N and mat[x][y] < mat[x + 1][y])
	{
            right = dfs(dp, mat, x + 1, y);
        }
        
        if ((y+1) < N and mat[x][y] < mat[x][y + 1])
	{
            down = dfs(dp, mat, x, y + 1);
        }

        dp[x][y] = 1 + max(right, down);
    }
    return dp[x][y];
}

int LIP(int mat[N][N]){
    int dp[N+1][N+1];
    memset(dp, -1, sizeof dp);
    return dfs(dp, mat, 0, 0);
}

int main(){
    int mat[N][N] = {
        { 1, 2, 3, 4 },
        { 2, 2, 3, 4 },
        { 3, 2, 3, 4 },
        { 4, 5, 6, 7 },
    };

    cout<<"Longest Increasing Path = "<<LIP(mat);

    return 0;
}

