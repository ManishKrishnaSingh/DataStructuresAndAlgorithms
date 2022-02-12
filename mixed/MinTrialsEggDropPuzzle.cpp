#include <bits/stdc++.h>

using namespace std;

int minEggDrop(int n, int k){
    if (k == 1 || k == 0 || n==1){
        return k;
    }

    int noOfDrops = INT_MAX;
    for(int f=1; f<=k; f++) {
        noOfDrops = min(noOfDrops, max(minEggDrop(n-1,f-1), minEggDrop(n,k-f)));
    }

    return 1+noOfDrops;
}

int dpEggDrop(int n, int k){
    int dp[n+1][k+1];

    // no of eggs 0 or 1
    for(int i=1;i<=n; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    // 1 egg and j floors
    for(int j=1; j<=k; j++){
        dp[1][j] = j;
    }

    int i,j,f;
    for(i=2; i<=n; i++){
        for(j=2; j<=k; j++){
            dp[i][j] = INT_MAX;
            for(f=1; f<=j; f++){
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][f-1],dp[i][j-f]));
            }
        }
    }

    return dp[n][k];
}

int main(){
    int n = 2, k = 10;

    int noOfDrops = minEggDrop(n, k);
    cout<<"Minimum Trials = "<<noOfDrops<<endl;

    int numOfDrops = dpEggDrop(n, k);
    cout<<"Minimum Trials = "<<numOfDrops<<endl;

    return 0;
}

