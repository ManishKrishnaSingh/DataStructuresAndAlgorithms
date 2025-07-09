#include <cstring>
#include <iostream>

using namespace std;

#define N 5

bool isSafe(int mat[N][N], int i, int j, bool visited[N][N]){
    return (i<N && i>=0 && j<N && j>=0 && !visited[i][j] && mat[i][j]==1);
}

void dfs(int mat[N][N], int i, int j, bool visited[N][N]){
    visited[i][j] = true;
    if(isSafe(mat, i+1, j, visited)){
        dfs(mat, i+1, j, visited);
    }
    if(isSafe(mat, i-1, j, visited)){
        dfs(mat, i-1, j, visited);
    }
    if(isSafe(mat, i, j+1, visited)){
        dfs(mat, i, j+1, visited);
    }
    if(isSafe(mat, i, j-1, visited)){
        dfs(mat, i, j-1, visited);
    }
    if(isSafe(mat, i+1, j+1, visited)){
        dfs(mat, i+1, j+1, visited);
    }
    if(isSafe(mat, i+1, j-1, visited)){
        dfs(mat, i+1, j-1, visited);
    }
    if(isSafe(mat, i-1, j+1, visited)){
        dfs(mat, i-1, j+1, visited);
    }
    if(isSafe(mat, i-1, j-1, visited)){
        dfs(mat, i-1, j-1, visited);
    }
}

int findCountOfIslands(int mat[N][N]){
    bool visited[N][N];
    memset(visited, false, sizeof(visited));

    int countOfIslands = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mat[i][j]==1 && !visited[i][j]){
                countOfIslands++;
                dfs(mat, i, j, visited);
            }
        }
    }
    return countOfIslands;
}

int main(){
    int mat[N][N] = {
        { 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 1 }
    };

    int nOfIslands = findCountOfIslands(mat);
    cout<<"Number of Islands = "<<nOfIslands<<endl;

    return 0;
}

