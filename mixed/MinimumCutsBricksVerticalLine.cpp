#include <bits/stdc++.h>

using namespace std;

/***************************************************************************
Draw a vertical line from the top to the bottom and cross the least bricks.
***************************************************************************/

int leastBricks(vector<vector<int>> wall){
    unordered_map<int,int> hashmap;

    int brickLineWidth;
    int maxGapBtwBricks = 0;
    for(auto bricks : wall){
        brickLineWidth = 0;
        for(int i=0; i<bricks.size()-1; i++){
            brickLineWidth += bricks[i];
            hashmap[brickLineWidth]++;
            if(maxGapBtwBricks < hashmap[brickLineWidth]){
                maxGapBtwBricks = hashmap[brickLineWidth];
            }
        }
    }
    return (wall.size()-maxGapBtwBricks);
}

int main(){
    vector<vector<int>> wall = {
        {1,2,2,1}, {3,1,2}, {1,3,2}, {2,4}, {3,1,2}, {1,3,1,1}
    };

    int minBrickCuts = leastBricks(wall);
    cout<<"minimum brick cuts = "<<minBrickCuts;

    return 0;
}