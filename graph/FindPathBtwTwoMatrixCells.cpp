#include <bits/stdc++.h>

using namespace std;

/**********************************************************************************************
Given N X N matrix filled with 1, 0, 2, 3. Find whether there is a path possible from source to
destination, traversing through blank cells only. You can traverse up, down, right, and left.
    - A value of cell 1 means Source.
    - A value of cell 2 means Destination.
    - A value of cell 3 means Blank cell.
    - A value of cell 0 means Blank Wall.
Note: there are an only a single source and single destination(sink). 
***********************************************************************************************/

vector<pair<int,int>> directions=
{
    {1,0}, {0,1}, {-1,0}, {0,-1}
};

bool IsSafe(vector<vector<int>>& mat, int& x, int& y, int& N)
{
    if(x>=0 && x<N && y>=0 && y<N)
    {
        return true;
    }
    return false;
}

bool dfs(vector<vector<int>>& mat, int x, int y, vector<vector<bool>> visit)
{
    visit[x][y] = true;

    if(mat[x][y]==2)
    {
        return true;
    }

    int newx, newy, n=mat.size();
    for(auto& direction : directions)
    {
        newx = x + direction.first;
        newy = y + direction.second;

        if(IsSafe(mat,newx,newy,n) and mat[newx][newy]!=0 and !visit[newx][newy])
        {
            if(dfs(mat, newx, newy, visit))
            {
                return true;
            }
        }
    }

    return false;
}

bool IsPathExist(vector<vector<int>>& mat)
{
    if(mat.size()==0 || mat[0].size()==0)
    {
        return false;
    }

    int i, j, n=mat.size();

    vector<vector<bool>> visit(n,vector<bool>(n,false));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j]==1 && !visit[i][j])
            {
                if(dfs(mat, i, j, visit))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix=
    {
        { 0, 3, 0, 1 },
        { 3, 0, 3, 3 },
        { 2, 3, 3, 3 },
        { 0, 3, 3, 3 }
    };

    cout<<"Path Exists ? "<<boolalpha<<IsPathExist(matrix);

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N^2)
*************************/
