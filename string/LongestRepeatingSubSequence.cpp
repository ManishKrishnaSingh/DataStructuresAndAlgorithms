#include <bits/stdc++.h>

using namespace std;

int findLongestRepeatingSubSeq(string iStr){
    int n = iStr.length();

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j && iStr[i-1] == iStr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

int main(){
    string str = "aabb";

    int length = findLongestRepeatingSubSeq(str);
    cout<<"Longest Repeating SubSeq = "<<length<<endl;

    return 0;
}

