#include <bits/stdc++.h>

using namespace std;

int dpShotestCommonSuperSequence(string X, string Y){
    int m = X.length();
    int n = Y.length();

    int dp[m+1][n+1];

    // fill table bottom up
    for(int i=0; i<= m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0){
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}


int main(){
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int result = dpShotestCommonSuperSequence(X, Y);
    cout<<"Shortest Common Super Sequence = "<<result;

    return 0;
}

