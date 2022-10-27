#include <bits/stdc++.h>

using namespace std;

int findLongestRepeatingSubSequenceLength(string iStr){
    int n = iStr.length();

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j and iStr[i-1] == iStr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

string findLongestRepeatingSubSequenceString(string iStr){
    int n = iStr.length();

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j and iStr[i-1] == iStr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string str = "";

    int i = n, j = n;
    while(i > 0 and j > 0){
        if(i != j and iStr[i-1] == iStr[j-1]){
            str = iStr[i-1] + str;
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
    string str = "aabfbcdd";

    int ssLength = findLongestRepeatingSubSequenceLength(str);
    cout<<"Longest Repeating Sub Sequence = "<<ssLength<<endl;

    string ssStr = findLongestRepeatingSubSequenceString(str);
    cout<<"Longest Repeating Sub Sequence = "<<ssStr<<endl;

    return 0;
}