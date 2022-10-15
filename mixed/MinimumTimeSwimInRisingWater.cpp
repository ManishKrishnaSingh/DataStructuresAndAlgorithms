#include<bits/stdc++.h>

using namespace std;

/** pair { height, pair { x, y } } */
typedef pair<int, pair<int,int>> Node;

int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int swimInWater(vector<vector<int>>& grid){
    int N = grid.size();

    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push({grid[0][0], {0, 0}});

    bool visited[N][N];
    memset(visited, false, sizeof(visited));

    int x, y, nx, ny;
    int swimTime = 0;
    visited[0][0] = true;

    while(true){
        auto top=pq.top();pq.pop();
        // x,y in the grid
        x = top.second.first;
        y = top.second.second;

        // update max swim time
        swimTime = max(swimTime, top.first);

        // reached the end
        if(x==N-1 && y==N-1){
            break;
        }

        for(auto dir : directions) {
            nx = x + dir[0];
            ny = y + dir[1];
            if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({grid[nx][ny], {nx, ny}});
            }
        }
    }

    return swimTime;
}

int main(){
    vector<vector<int>> grid = {
        { 0,  1,  2,  3,  4},
        {24, 23, 22, 21,  5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10,  9,  8,  7,  6}
    };

    int swimTime = swimInWater(grid);
    cout<<"Minimum Time = "<<swimTime;

    return 0;
}
