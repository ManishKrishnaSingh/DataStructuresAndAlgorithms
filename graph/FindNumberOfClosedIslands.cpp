#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> directions =
{
    {1,0}, {0,1}, {-1,0}, {0,-1}
};

bool IsSafe(int& x, int& y, int& M, int& N)
{
    if(x >= 0 && x < M && y >= 0 && y < N)
    {
        return true;
    }
    return false;
}

bool IsCellOnEdge(int& x, int& y, int& M, int& N)
{
    if(x==0 || x==M-1 || y==0 || y==N-1)
    {
        return true;
    }
    return false;
}

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, int& M, int& N, bool& hasCellOnEdge)
{
    if (!IsSafe(x,y,M,N) || visited[x][y]==true || matrix[x][y]==0)
    {
        return;
    }

    if(IsCellOnEdge(x,y,M,N))
    {
        if(matrix[x][y] == 1)
        {
            hasCellOnEdge = true;
        }
    }

    visited[x][y] = true;

    for(auto& dir : directions)
    {
        dfs(matrix, visited, x+dir.first, y+dir.second, M, N, hasCellOnEdge);
    }
}

int findCountClosedIslands(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0)
    {
        return 0;
    }

    int M = matrix.size();
    int N = matrix[0].size();

    vector<vector<bool>> visited(M, vector<bool>(N, false));

    int i,j,numOfIslands=0;
    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            if (!IsCellOnEdge(i,j,M,N) and !visited[i][j] and matrix[i][j]==1)
            {			
                bool hasCellOnEdge = false;

                dfs(matrix, visited, i, j, M, N, hasCellOnEdge);
				
                if(!hasCellOnEdge)
                {
                    numOfIslands++;
                }
            }
        }
    }

    return numOfIslands;
}

int main()
{
    vector<vector<int> > matrix =
    {
        { 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 0, 0, 1 },
        { 0, 1, 0, 1, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1 }
    };

    cout <<"Number of Closed Islands = "<<findCountClosedIslands(matrix);

    return 0;
}


/************************
Time Complexity  : O(M*N)
Space Complexity : O(M*N)
*************************/