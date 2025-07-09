#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Cell;

vector<pair<int,int>> knightMoves =
{
    {2, 1}, {2, -1}, {-2,1}, {-2,-1}, {1, 2}, {1, -2}, {-1,2}, {-1,-2}
};

bool IsSafe(int& x, int& y, int& N)
{
    if(x >= 1 && x <= N && y >= 1 && y <= N)
    {
        return true;
    }
    return false;
}

int minStepToReachTarget(Cell& posKnight, Cell& posTarget, int& N)
{
    vector<vector<bool>> visit(N+1,vector<bool>(N+1,false));

    queue<Cell> knightPosQue;
    knightPosQue.push(posKnight);

    int x = posKnight.first;
    int y = posKnight.second;

    visit[x][y] = true;

    Cell currKnightPos;
    int minSteps = 0, size;

    while(!knightPosQue.empty())
    {
        minSteps++;

        size = knightPosQue.size();

        while(size--)
        {
            currKnightPos=knightPosQue.front(); knightPosQue.pop();

            if(currKnightPos == posTarget)
            {
                return minSteps;
            }

            for(auto& knightMove : knightMoves)
            {
                x = currKnightPos.first  + knightMove.first;
                y = currKnightPos.second + knightMove.second;

                if(IsSafe(x,y,N) && !visit[x][y])
                {
                    visit[x][y] = true;
                    knightPosQue.push({x,y});
                }
            }
        }
    }

    return -1;
}

int main()
{
    int N = 30;

    Cell posKnight = { 1, 1};
    Cell posTarget = {30,30};

    cout<<"Minimum Steps To Reach Target = "<<minStepToReachTarget(posKnight, posTarget, N);

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N^2)
*************************/