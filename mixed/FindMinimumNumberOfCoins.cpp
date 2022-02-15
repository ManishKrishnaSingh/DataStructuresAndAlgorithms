#include<bits/stdc++.h>

using namespace std;

int minCoins(int coins[], int n, int T){
    int dp[T+1];

    for(int i=0; i<=T; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    for(int i=1; i<=T; i++){
        for(int j=0; j<n; j++){
            if(coins[j] <= i){
                int nCoins = dp[i-coins[j]];
                if(nCoins!=INT_MAX && nCoins+1 < dp[i]){
                    dp[i] = nCoins+1;
                }
            }
        }
    }

    if(dp[T]==INT_MAX){
        return -1;
    }

    return dp[T];
}

int main(){
    int TargetValue = 11;
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);

    int nCoins = minCoins(coins, n, TargetValue);
    cout << "Minimum coins required = "<<nCoins;

    return 0;
}

