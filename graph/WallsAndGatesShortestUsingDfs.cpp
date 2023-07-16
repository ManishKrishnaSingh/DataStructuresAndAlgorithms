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

void dfs(vector<vector<int>>& rooms, int x, int y, int& R, int& C, int distance)
{
    if(!IsSafe(x,y,R,C) || rooms[x][y] < distance)
    {
        return;
    }

    rooms[x][y] = distance;

    for(auto& dir : directions)
    {
        dfs(rooms, x+dir.first, y+dir.second, R, C, distance+1);
    }
}

void solveWallsAndGates(vector<vector<int>>& rooms)
{
    if(rooms.size() == 0 || rooms[0].size() == 0)
    {
        return;
    }
 
    int R = rooms.size();
    int C = rooms[0].size();
 
    int x, y;
    for(x = 0; x < R; x++)
    {
        for(y = 0; y < C; y++)
        {
            if(rooms[x][y] == 0)
            {
                dfs(rooms, x, y, R, C, 0);
            }
        }
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
Space Complexity : O(1)
*************************/
