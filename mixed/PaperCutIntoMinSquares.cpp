#include <climits>
#include <iostream>

using namespace std;

int dp[100][100];

int minSquares(int X, int Y){
    if(X==Y){
        return 1;
    }

    // exception: when lengths are 11 and 13
    if((X==11 and Y==13) || (X==13 and Y==11)){
        return 6;
    }

    if(dp[X][Y]){
        return dp[X][Y];
    }

    int minHor=INT_MAX, minVer=INT_MAX;
    for(int x=1; x<=X/2; x++){
        minHor = min(minHor, minSquares(x,Y)+minSquares(X-x,Y));
    }
    for(int y=1; y<=Y/2; y++){
        minVer = min(minVer, minSquares(X,y)+minSquares(X,Y-y));
    }

    return dp[X][Y] = min(minHor, minVer);
}

int main(){
    int X = 30, Y = 35;

    int nSquares = minSquares(X, Y);
    cout<<"Min Squares = "<<nSquares;

    return 0;
}

