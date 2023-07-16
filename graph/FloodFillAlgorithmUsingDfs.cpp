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

void dfs(vector<vector<int>>& screen, int x, int y, int& M, int& N, int& pColor, int& nColor)
{
    if(!IsSafe(x,y,M,N) || screen[x][y] != pColor)
    {
        return;
    }
	
    screen[x][y] = nColor;
	
    for(auto& dir : directions)
    {
        dfs(screen, x+dir.first, y+dir.second, M, N, pColor, nColor);
    }
}

void floodFill(vector<vector<int>>& screen, int x, int y, int& pColor, int& nColor)
{
    if(screen.size()==0 || screen[0].size()==0)
    {
        return;
    }

    int i, j;
    int M = screen.size();
    int N = screen[0].size();

    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(screen[x][y] == pColor)
            {
                dfs(screen, x, y, M, N, pColor, nColor);
            }
        }
    }
}

void PrintScreen(vector<vector<int>>& screen)
{
    if(screen.size()==0 || screen[0].size()==0)
    {
        return;
    }

    int i, j;
    int M = screen.size();
    int N = screen[0].size();

    for(i = 0; i < M; i++)
    {
        cout<<endl; //newline
        for(j = 0; j < N; j++)
        {
            cout<<screen[i][j]<<"\t";
        }
    }
}

int main()
{
    vector<vector<int>> screen =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1}
    };

    int x=4,y=4;//curr color co-ordinate

    //current color and the new color
    int pColor=screen[x][y], nColor=3;

    floodFill(screen, x, y, pColor, nColor);
    
    PrintScreen(screen);

    return 0;
}

/************************
Time Complexity  : O(M*N)
Space Complexity : O(M*N)
*************************/