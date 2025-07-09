/*****************************************************************************
- Shortest path by removing K walls
- Shortest Path in a Grid with Obstacles Elimination

Given an MxN integer matrix, where each cell is either 0 (empty) or 1 (obstacle).
You can move up, down, left, or right from and to an empty cell in one step.

Return
Minimum number of steps to walk from the upper left corner {0,0} to the {M-1,N-1}
given that you can eliminate at most k obstacles.
If it is not possible to find such walk return -1.
******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool IsSafe(int& x, int& y, int& M, int& N)
{
    if(x >= 0 and x < M and y >= 0 and y < N)
    {
        return true;
    }
    return false;
}

int shortestPathWithObstacles(vector<vector<int>>& grid, int& K)
{
    int M = grid.size();
    int N = grid[0].size();

    int distance[M][N][K+1];
    memset(distance, 0, sizeof distance);

    bool visited[M][N][K+1];
    memset(visited, false, sizeof visited);

    queue<vector<int>> queue;

    // BFS/floodfill
    queue.push({0, 0, 0});
    visited[0][0][0] = true;

    while (!queue.empty())
    {
        auto curr = queue.front();
        queue.pop();

        int& x = curr[0];
        int& y = curr[1];
        int& k = curr[2];

        // Reached the Target Cell
        if (x == M-1 and y == N-1)
        {
            return distance[x][y][k];
        }

        for (auto& dir : dirs)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;
            int nk = k;

            if (!IsSafe(nx, ny, M, N))
            {
                continue;
            }
			
            if(grid[nx][ny] == 1)
            {
                nk++;
            }

            if(nk > K || visited[nx][ny][nk])
            {
                continue;
            }

            queue.push({nx, ny, nk});
            visited[nx][ny][ny] = true;
            distance[nx][ny][nk] = distance[x][y][k] + 1;
        }
    }

    return -1;
}

int main()
{
    int K = 1;
    vector<vector<int>> grid =
    {
        { 0, 0, 0 },
        { 1, 1, 0 },
        { 0, 0, 0 },
        { 0, 1, 1 },
        { 0, 0, 0 }
    };

    cout<<"Shortest Path = "<<shortestPathWithObstacles(grid, K);

    return 0;
}

/****************************
Time Complexity  : O(M*N*K)
Space Complexity : O(M*N*K)
*****************************/