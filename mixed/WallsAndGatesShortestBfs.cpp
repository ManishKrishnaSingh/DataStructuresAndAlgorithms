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
    int rows = rooms.size();
    int cols = rooms[0].size();

    bool visit[rows][cols];
    memset(visit, false, sizeof(visit));

    int r,c, x,y, nx,ny,size;

    queue<pair<int,int>> queue;

    // add gates to the queue
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            if(rooms[r][c] == 0)
            {
                queue.push({r,c});
                visit[r][c] = true;
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

            for(auto dir : directions)
            {
                // new coordinates
                nx = x + dir.first;
                ny = y + dir.second;

                if(IsSafe(nx,ny,rows,cols) && !visit[nx][ny] && rooms[nx][ny] == INF)
                {
                    queue.push({nx,ny});
                    visit[nx][ny] = true;
                }
            }
        }

        distance += 1; // increament the distance
    }
    
    // print latest status
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            cout<<rooms[r][c]<<"\t";
        }
        cout<<endl; //end of line
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