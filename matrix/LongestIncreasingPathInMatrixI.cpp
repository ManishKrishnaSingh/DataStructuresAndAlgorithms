#include <cstring>
#include <iostream>

const int N = 4;

using namespace std;

int LipUtil(int dp[N+1][N+1], int mat[N][N], int x, int y){
    if (dp[x][y] < 0) {

        if (x == N-1 && y == N-1){
            return dp[x][y] = 1;
        }

        int result = 0;
        if (x == N-1 || y == N-1){
            result = 1;
        }
        
        if (mat[x][y] < mat[x + 1][y]){
            result = max(result, 1 + LipUtil(dp, mat, x + 1, y));
        }
        
        if (mat[x][y] < mat[x][y + 1]){
            result = max(result, 1 + LipUtil(dp, mat, x, y + 1));
        }
        dp[x][y] = result;
    }
    return dp[x][y];
}

int LIP(int mat[N][N]){
    int dp[N+1][N+1];
    memset(dp, -1, sizeof dp);
    return LipUtil(dp, mat, 0, 0);
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

