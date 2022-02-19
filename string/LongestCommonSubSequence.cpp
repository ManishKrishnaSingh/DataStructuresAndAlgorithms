#include <bits/stdc++.h>

using namespace std;

int findLongestCommonSubSequence(string iStr1, string iStr2){
    int m = iStr1.length();
    int n = iStr2.length();

    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(iStr1[i-1] == iStr2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main(){
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    int length=findLongestCommonSubSequence(str1, str2);
    cout<<"Longest Common Sub Sequence = "<<length<<endl;

    return 0;
}

