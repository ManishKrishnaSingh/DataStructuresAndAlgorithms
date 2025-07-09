#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Cell;

vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

/****************************************************************************
You are given an m x n grid where each cell can have one of three values:
 - 0 representing an empty cell
 - 1 representing a fresh orange
 - 2 representing a rotten orange
Every min,any fresh orange that is adjacent to a rotten orange becomes rotten

Return
- Minimum no of minutes that must elapse until no cell has a fresh orange.
- in case it is impossible(there still remains a fresh apple in the end),-1.
****************************************************************************/

int minimumTimeOrangesRotting(vector<vector<int>>& grid){
    if(grid.size()){
        int R = grid.size();
        int C = grid[0].size();

        bool visit[R][C];
        memset(visit,0,sizeof(visit));

        queue<Cell> queue;
        int freshapples = 0;
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                if(grid[r][c] == 1){
                    freshapples++;
                } else if(grid[r][c] == 2){
                    queue.push({r, c});
                    visit[r][c] = true;
                }
            }
        }

        int x, y, minutes = 0;
        while(!queue.empty() and freshapples>0){
            minutes++;
            int sz = queue.size();
            while(sz--){
                auto cell=queue.front(); queue.pop();
                for(auto dir : directions){
                    x = cell.first + dir[0];
                    y =  cell.second + dir[1];
                    if(x>=0 && x<R && y>=0 && y<C && grid[x][y]==1 && !visit[x][y]){
                        freshapples--;
                        queue.push({x, y});
                        visit[x][y] = true;
                    }
                }
            }
        }

        if(freshapples > 0){
            minutes = -1;
        }

        return minutes;
    }

    return 0;
}

int main(){
    vector<vector<int>> grid = {
        {2,1,1}, {1,1,0}, {0,1,1}
    };

    int minutes = minimumTimeOrangesRotting(grid);
    cout<<"Min time to rot all oranges = "<<minutes;

    return 0;
}