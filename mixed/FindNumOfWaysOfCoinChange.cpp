#include<bits/stdc++.h>

using namespace std;

int noWaysOfCoinChange(int coins[], int n, int sum){
    if (sum == 0){
        return 1;
    }
    if (sum < 0){
        return 0;
    }
    if (n <= 0){
        return 0;
    }

    return noWaysOfCoinChange(coins, n-1, sum) + noWaysOfCoinChange(coins, n, sum-coins[n-1]);
}

int dpWaysOfCoinChange(int coins[], int n, int sum){
    int dp[sum+1][n];

    //when the sum is zero
    for(int i=0; i<n; i++){
        dp[0][i] = 1;
    }

    //update bottom-up fashion
    for(int i=1; i<=sum; i++){
        for(int j=0; j<n; j++){
            // no of solutions excluding coins[j]
            int nWaysExcl = (j >=1 ) ? dp[i][j-1] : 0;
            // no of solutions including coins[j]
            int nWaysIncl = ((i-coins[j]) >= 0) ? dp[i-coins[j]][j] : 0;
            // total no of ways to solutions
            dp[i][j] = nWaysExcl + nWaysIncl;
        }
    }
    return dp[sum][n-1];
}

int main(){
    int sum = 11;

    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);

    int rcNoOfWays = noWaysOfCoinChange(coins, n, sum);
    cout<<"No of Ways[Coin Change] = "<<rcNoOfWays<<"\n";

    int dpNoOfWays = dpWaysOfCoinChange(coins, n, sum);
    cout<<"No of Ways[Coin Change] = "<<dpNoOfWays<<"\n";;

    return 0;
}
