#include <bits/stdc++.h>

using namespace std;

bool matches(string str, string pat, int m, int n){
    if(m == 0 && n==0){
        return true;
    }

    bool dp[m+1][n+1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;
    // '*' with empty string
    for(int j=1; j<=n; j++){
        if(pat[j-1] == '*'){
            dp[0][j] = dp[0][j-1];
        }
    }

    // fill dp bottom-up fashion
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if (pat[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            } else if(pat[j-1]=='?' || str[i-1]==pat[j-1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}

int main(){
    string str = "baaabab";
    string pat = "*****ba*****ab";

    bool IsMatch = matches(str,pat,str.length(),pat.length());
    cout<<"Found the regex match = "<<boolalpha<<IsMatch<<endl;

    return 0;
}

