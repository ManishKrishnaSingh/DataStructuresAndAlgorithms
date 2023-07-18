#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> directions =
{
    {1,0}, {0,1}, {-1, 0}, {0, -1}
};

bool IsSafe(int i, int j, int& ROW, int& COL)
{
    return (i >= 0 && i < ROW && j >= 0 && j < COL);
}

int minimumCostPath(vector<vector<int>>& grid)
{
    if(grid.size() == 0 || grid[0].size() == 0)
    {
        return -1;
    }

    int ROW = grid.size();
    int COL = grid[0].size();

    vector<vector<int>> distance(ROW, vector<int>(COL,INT_MAX));

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
	
    minHeap.push({0, {0,0}});

    distance[0][0] = grid[0][0];

    // Dijkstra's Algos
    int x,y, newx,newy;
    while(!minHeap.empty())
    {
        auto top = minHeap.top(); minHeap.pop();

        x = top.second.first;
        y = top.second.second;

        for(auto& dir : directions)
        {
            newx = x + dir.first;
            newy = y + dir.second;

            if(!IsSafe(newx, newy, ROW, COL))
            {
                continue;
            }

            if(distance[x][y] != INT_MAX and distance[newx][newy] > (distance[x][y] + grid[newx][newy]))
            {
                distance[newx][newy] = distance[x][y] + grid[newx][newy];

                minHeap.push({distance[newx][newy], {newx,newy}});
            }
        }
    }

    return distance[ROW-1][COL-1];
}

int main()
{
    vector<vector<int>> grid =
    {
        { 31, 100,  65,  12,  18},
        { 10,  13,  47, 157,   6},
        {100, 113, 174,  11,  33},
        { 88, 124,  41,  20, 140},
        { 99,  32, 111,  41,  20}
    };

    cout<<"Minimum Cost = "<<minimumCostPath(grid);

    return 0;
}
