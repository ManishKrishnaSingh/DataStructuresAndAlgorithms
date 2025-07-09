/****************************************************************************
Given an NxN Int matrix, where each grid[i][j] represents elevation at {i,j}.

The rain starts to fall.   At time T, depth of the water everywhere is T. You
can swim from a square to another 4-directionally adjacent square if and only
if the elevation  of both  squares individually are at most T.  You  can swim
infinite distances in zero time.   You must stay within the boundaries of the
grid during your swim.

Return
Least time until you can reach the bottom right square (N-1,N-1) if you start
at the top left square (0,0).
****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define N 5

vector<pair<int,int>> dirs = {{1,0}, {0,1}, {0,-1}, {-1,0}};

bool IsSafe(int& x, int& y) {
    if(x >=0 and x < N and y >= 0 and y < N) {
        return true;
    }
    return false;
}

bool IsPossible(int grid[N][N], int tm) {
    if(grid[0][0] > tm) {
        return false;
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int,int>> queue;

    queue.push({0,0});
    visited[0][0] = true;

    while(!queue.empty()) {
        int& x = queue.front().first;
        int& y = queue.front().second;

        queue.pop();

        for(auto& dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if(IsSafe(nx, ny) && !visited[nx][ny] && grid[nx][ny] <= tm) {
                queue.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }

    return visited[N-1][N-1];
}

int swimInWater(int grid[N][N]) {
    int low=0, mid, high=N*N;
    while (low+1 < high) {
        mid = (low + high) / 2;
        if(IsPossible(grid, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {
    int grid[N][N] = {
        { 0, 1, 2, 3, 4},
        {24,23,22,21, 5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10, 9, 8, 7, 6}
    };

    cout<<"Minimum Time to Swim = "<<swimInWater(grid)<<endl;

    return 0;
}
