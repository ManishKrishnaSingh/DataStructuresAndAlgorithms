#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int shortestPath(vector<vector<int>> mat, int K)
{
    int M = mat.size();
    int N = mat[0].size();

    if (M==1 && N==1 && (mat[0][0]==0 || K>=1))
    {
        return 0;
    }

    bool visited[M][N][K+1];
    memset(visited, false, sizeof visited);

    queue<vector<int>> que;
    que.push({0, 0, K});

    int minSteps = 0;
    int x,y,k, nx,ny,nk, size;

    while (!que.empty())
    {
        minSteps++;

        size = que.size();
        while (size--)
        {
            auto curr = que.front(); que.pop();
            x = curr[0]; y = curr[1]; k = curr[2];

            visited[x][y][k] = true;
            for (auto& dir : dirs)
            {
                nx=x+dir.first; ny=y+dir.second; nk=k;
                if (nx >= 0 && nx < M && ny >= 0 && ny < N)
                {
                    if (nx == M-1 && ny == N-1)
                    {
                        return minSteps;
                    }

                    if (mat[nx][ny] == 0 && !visited[nx][ny][nk])
                    {
                        que.push({ nx, ny, nk });
                        visited[nx][ny][nk] = true;
                    }
                    else if (mat[nx][ny] == 1 && nk >= 1 && !visited[nx][ny][nk-1])
                    {
                        // break the wall
                        que.push({ nx, ny, nk-1});
                        visited[nx][ny][nk-1] = true;
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    int K = 1;
    vector<vector<int>> mat =
    {
        { 0, 0, 0 },
        { 0, 0, 1 },
        { 0, 1, 0 }
    };

    cout<<"Shortest Path = "<<shortestPath(mat, K);

    return 0;
}

/****************************
Time Complexity  : O(M*N*K)
Space Complexity : O(M*N*K)
*****************************/