#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

#define N 5

bool isSafe(int mat[N][N], int i, int j, bool visited[N][N]){
    return (i<N && i>=0 && j<N && j>=0 && !visited[i][j] && mat[i][j]==1);
}

void bfs(int mat[N][N], int i, int j, bool visited[N][N]){

    queue<pair<int,int>> queue;
    queue.push(make_pair(i,j));
    visited[i][j] = true;

    while(!queue.empty()){
        pair<int,int> front = queue.front();
        queue.pop();

        int x = front.first;
        int y = front.second;

        if(isSafe(mat, x+1, y, visited)){
            visited[x+1][y] = true;
            queue.push(make_pair(x+1, y));
        }
        if(isSafe(mat, x-1, y, visited)){
            visited[x-1][y] = true;
            queue.push(make_pair(x-1, y));
        }
        if(isSafe(mat, x, y+1, visited)){
            visited[x][y+1] = true;
            queue.push(make_pair(x, y+1));
        }
        if(isSafe(mat, x, y-1, visited)){
            visited[x][y-1] = true;
            queue.push(make_pair(x, y-1));
        }
        if(isSafe(mat, x+1, y+1, visited)){
            visited[x+1][y+1] = true;
            queue.push(make_pair(x+1, y+1));
        }
        if(isSafe(mat, x+1, y-1, visited)){
            visited[x+1][y-1] = true;
            queue.push(make_pair(x+1, y-1));
        }
        if(isSafe(mat, x-1, y+1, visited)){
            visited[x-1][y+1] = true;
            queue.push(make_pair(x-1, y+1));
        }
        if(isSafe(mat, x-1, y-1, visited)){
            visited[x-1][y-1] = true;
            queue.push(make_pair(x-1, y-1));
        }
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
                bfs(mat, i, j, visited);
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

