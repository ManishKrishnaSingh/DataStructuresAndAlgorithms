#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

vector<pair<int,int>> directions = 
{
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool IsSafe(int& x, int& y, int& R, int& C)
{
    if(x >= 0 && x < R && y >= 0 && y < C)
    {
        return true;
    }
    return false;
}

void solveWallsAndGates(vector<vector<int>>& rooms)
{
    if(rooms.size() == 0 || rooms[0].size() == 0)
    {
        return;
    }

    int R = rooms.size();
    int C = rooms[0].size();

    bool visit[R][C];
    memset(visit, false, sizeof(visit));

    int x, y, nx, ny, size;

    queue<pair<int,int>> queue;

    // add gates to the queue
    for(x = 0; x < R; x++)
    {
        for(y = 0; y < C; y++)
        {
            if(rooms[x][y] == 0)
            {
                queue.push({x, y});
                visit[x][y] = true;
            }
        }
    }

    int distance = 0;

    while(!queue.empty())
    {
        size = queue.size();

        while (size--)
        {
            auto front=queue.front(); queue.pop();

            // coordinates
            x = front.first;
            y = front.second;

            // update distance
            rooms[x][y] = distance;

            for(auto& dir : directions)
            {
                // new coordinates
                nx = x + dir.first;
                ny = y + dir.second;

                if(IsSafe(nx,ny,R,C) && !visit[nx][ny] && rooms[nx][ny] == INF)
                {
                    queue.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }

        distance += 1; // increament the distance
    }
    
    // Print Latest Status
    for(x = 0; x < R; x++)
    {
        cout<<endl; // new line
        for(y = 0; y < C; y++)
        {
            cout<<rooms[x][y]<<"\t";
        }
    }
}

int main()
{
    vector<vector<int>> rooms =
    {
        {INF, -1 ,   0, INF},
        {INF, INF, INF,  -1},
        {INF, -1 , INF,  -1},
        {0  , -1 , INF, INF}
    };

    solveWallsAndGates(rooms);

    return 0;
}

/************************
Time Complexity  : O(R*C)
Space Complexity : O(R*C)
*************************/