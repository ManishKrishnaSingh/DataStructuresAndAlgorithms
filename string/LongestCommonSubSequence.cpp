#include <bits/stdc++.h>

using namespace std;

int findLongestCommonSubSequenceLength(string xStr, string yStr){
    int m = xStr.length();
    int n = yStr.length();

    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(xStr[i-1] == yStr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

string findLongestCommonSubSequenceString(string xStr, string yStr){
    int m = xStr.length();
    int n = yStr.length();

    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(xStr[i-1] == yStr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string str = "";

    int i = m, j = n;
    while(i > 0 and j > 0){
        if(xStr[i-1] == yStr[j-1]){
            str = xStr[i-1] + str;
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }

    return str;
}

int main(){
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    int ssLength = findLongestCommonSubSequenceLength(str1, str2);
    cout<<"Longest Common Sub Sequence = "<<ssLength<<endl;

    string ssStr = findLongestCommonSubSequenceString(str1, str2);
    cout<<"Longest Common Sub Sequence = "<<ssStr<<endl;

    return 0;
}