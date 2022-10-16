#include <bits/stdc++.h>

using namespace std;

const int INF = 2147483647;

vector<pair<int,int>> directions = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

void wallsAndGates(vector<vector<int>> &rooms){
    int rows = rooms.size();
    int cols = rooms[0].size();

    bool visit[rows][cols];
    memset(visit, false, sizeof(visit));

    queue<pair<int,int>> queue;
    // add gates to the queue
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            if(rooms[r][c] == 0){
                queue.push({r,c});
                visit[r][c] = true;
            }
        }
    }

    int x, y, nx, ny;
    int distance = 0;
    // bfs to find distance
    while(!queue.empty()){
        int size = queue.size();
        while (size--){
            auto front=queue.front();
            queue.pop();
            // coordinates
            x = front.first;
            y = front.second;
            // update distance
            rooms[x][y] = distance;
            for(auto dir : directions){
                // new coordinates
                nx = x + dir.first;
                ny = y + dir.second;
                if(nx>=0 && nx<rows && ny>=0 && ny<cols && !visit[nx][ny] && rooms[nx][ny] == INF){
                    queue.push({nx,ny});
                    visit[nx][ny] = true;
                }
            }
        }
        distance += 1; // increament distance
    }
    
    // print rooms latest status
    for(int r=0; r < rows; r++){
        for(int c=0; c<cols; c++){
            cout<<rooms[r][c]<<" ";
        }
        cout<<endl; //end of line
    }
}

int main(){
    vector<vector<int>> rooms = {
        {INF, -1 ,   0, INF},
        {INF, INF, INF,  -1},
        {INF, -1 , INF,  -1},
        {0  , -1 , INF, INF}
    };

    wallsAndGates(rooms);

    return 0;
}