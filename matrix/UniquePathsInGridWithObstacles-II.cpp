#include <bits/stdc++.h>

using namespace std;

#define N 3

bool IsSafe(int mat[N][N], int i, int j){
    if(i>=0 and i<N and j>=0 and j<N){
        return mat[i][j] == 0;
    }
    return false;
}

void dfs(int mat[N][N], int i, int j, int& uniqPaths){
    if(i == N-1 and j == N-1){
        uniqPaths++;
    } else {
        if(IsSafe(mat, i+1, j)){
            dfs(mat, i+1, j, uniqPaths);
        }
        if(IsSafe(mat, i, j+1)){
            dfs(mat, i, j+1, uniqPaths);
        }
    }
}

int uniquePathsInGrid(int mat[N][N]){
    if(mat[0][0]==1 || mat[N-1][N-1]==1)
        return 0;

    int uniqPaths = 0;
    dfs(mat, 0, 0, uniqPaths);

    return uniqPaths;
}

int main(){
    int mat[N][N] = {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 }
    };

    int nUniquePaths = uniquePathsInGrid(mat);
    cout<<"\n[Unique Paths] = "<<nUniquePaths;

    return 0;
}
