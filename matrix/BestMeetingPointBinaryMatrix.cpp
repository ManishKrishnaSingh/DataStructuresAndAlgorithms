#include <bits/stdc++.h>

using namespace std;

#define ROW 3
#define COL 5

int findMinimumTotalDistance(int grid[][COL]) {
    if(ROW==0 || COL==0){
        return 0;
    }

    vector<int> vertical;
    vector<int> horizontal;
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(grid[i][j]==1){
                vertical.push_back(i);
                horizontal.push_back(j);
            }
        }
    }

    int mid = vertical.size()/2;

    sort(vertical.begin(),vertical.end());
    sort(horizontal.begin(),horizontal.end());

    int x = vertical[mid];
    int y = horizontal[mid];
    //find manhattan distance
    int manhattandistance = 0;
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(grid[i][j]==1){
                manhattandistance += abs(x-i)+abs(y-j);
            }
        }
    }

    return manhattandistance;
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int distance = findMinimumTotalDistance(grid);
    cout<<"Distance to meeting point = "<<distance;

    return 0;
}

