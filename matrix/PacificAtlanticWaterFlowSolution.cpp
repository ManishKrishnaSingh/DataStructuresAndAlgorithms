#include <bits/stdc++.h>

using namespace std;

struct myHashFunc {
    size_t operator()(const pair<int,int>& mypair) const{
        return mypair.first ^ mypair.second;
    }
};

void dfs(int x, int y, int R, int C, vector<vector<int>>& heights, int prevHeight, unordered_set<pair<int,int>,myHashFunc>& visit){
    if(visit.count({x,y})==0 and x>=0 and x<R and y>=0 and y<C and heights[x][y]>=prevHeight){
        visit.insert({x,y});
        dfs(x+1, y, R, C, heights, heights[x][y], visit);
        dfs(x-1, y, R, C, heights, heights[x][y], visit);
        dfs(x, y+1, R, C, heights, heights[x][y], visit);
        dfs(x, y-1, R, C, heights, heights[x][y], visit);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
    vector<vector<int>> result;

    if(heights.size() > 0){
        int rows = heights.size();
        int cols = heights[0].size();

        unordered_set<pair<int,int>,myHashFunc> pacific;
        unordered_set<pair<int,int>,myHashFunc> atlantic;

        // start with first and last row
        for(int c=0; c < cols; c++){
            dfs(0, c, rows, cols, heights, heights[0][c], pacific);
            dfs(rows-1, c, rows, cols, heights, heights[rows-1][c], atlantic);
        }
        // start with first and last col
        for(int r=0; r < rows; r++){
            dfs(r, 0, rows, cols, heights, heights[r][0], pacific);
            dfs(r, cols-1, rows, cols, heights, heights[r][cols-1], atlantic);
        }

        // fill the result set
        for(int r=0; r < rows; r++){
            for(int c=0; c < cols; c++){
                //add cell into result which can go to both oceans
                if(pacific.count({r,c}) && atlantic.count({r,c})){
                    result.push_back({r, c});
                }
            }
        }
    }

    return result;
}

int main(){
    vector<vector<int>> heights={
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    
    auto coordinates = pacificAtlantic(heights);
    for(auto coordinate : coordinates){
        cout<<"{"<<coordinate[0]<<", "<<coordinate[1]<<"}\n";
    }
    return 0;
}
