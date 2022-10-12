#include <bits/stdc++.h>

using namespace std;

int numOfWaysClimbStairs(int nStairs, int maxSteps){
    int dp[nStairs+1];
    dp[0] = dp[1] = 1;
    for(int i=2; i<=nStairs; i++){
        dp[i] = 0;
        for(int j=1; j<= maxSteps && j<=i; j++){
            dp[i] += dp[i-j];
        }
    }
    return dp[nStairs];
}

int main(){
    int nStairs=4, maxSteps=2;
    int nWays=numOfWaysClimbStairs(nStairs,maxSteps);
    cout<<"Number Of Ways To Climb stairs = "<<nWays;
    return 0;
}