#include <iostream>

using namespace std;

int findLCS(string X, string Y, int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    if(X[m-1]==Y[n-1]){
        return 1 + findLCS(X, Y, m-1, n-1);
    } else {
        return max(findLCS(X, Y, m, n-1), findLCS(X, Y, m-1, n));
    }
}

int dpLongestCommonSubsequence(string X, string Y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(X[i-1]==Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

string dpLongestCommonSubsequenceStr(string X, string Y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(X[i-1]==Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i=m, j=n;
    string oStr="";
    while(i>0 && j>0){
        if (X[i-1] == Y[j-1]){
            oStr= X[i-1]+oStr;
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    return oStr;
}

int main(){
    string X="AGGTAB", Y="GXTXAYB";
    int m=X.length(), n=Y.length();

    int lcsLen = findLCS(X, Y, m, n);
    cout<<"Length [Longest Common Subsequence] = "<<lcsLen<<endl;

    int dpLcsLen = dpLongestCommonSubsequence(X, Y, m, n);
    cout<<"Length [Longest Common Subsequence] = "<<dpLcsLen<<endl;

    string dpLcsStr = dpLongestCommonSubsequenceStr(X, Y, m, n);
    cout<<"String [Longest Common Subsequence] = "<<dpLcsStr<<endl;

    return 0;
}

