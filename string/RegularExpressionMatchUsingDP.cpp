#include <bits/stdc++.h>

using namespace std;

/**********************************************/
/** Regular Expression Match: DP (Top-Down)  **/
/**********************************************/
bool matchesTopDown(string txt, string pat){
    int m = txt.length();
    int n = pat.length();

    bool **dp = new bool*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new bool [n+1];
        for(int j=0; j<=n; j++){
            dp[i][j] = false;
        }
    }

    dp[m][n] = true;
    for(int i=m; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            bool IsMatch = (i<m && (pat[j]==txt[i] || pat[j]=='.'));
            if(j+1 < n && pat[j+1]=='*'){
                dp[i][j] = dp[i][j+2] || (IsMatch && dp[i+1][j]);
            } else {
                dp[i][j] = (IsMatch && dp[i+1][j+1]);
            }
        }
    }

    return dp[0][0];
}

/**********************************************/
/** Regular Expression Match: DP (Bottom-Up) **/
/**********************************************/
bool matchesBottomUp(string txt, string pat){
    int m = txt.length();
    int n = pat.length();

    bool **dp = new bool*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new bool [n+1];
        for(int j=0; j<=n; j++){
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for(int i=1; i<=n; i++){
        if(pat[i-1] == '*'){
            dp[0][i] = dp[0][i-2];
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(pat[j-1]=='.' || pat[j-1]==txt[i-1]){
                dp[i][j] = dp[i-1][j-1];
            } else if(pat[j-1]=='*'){
                dp[i][j] = dp[i][j-2];
                if(pat[j-2]=='.' || pat[j-2]==txt[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout<<"\nIs Match[DP-TD]: "<<boolalpha<<matchesTopDown("axxe", "ax*e");
    cout<<"\nIs Match[DP-BU]: "<<boolalpha<<matchesBottomUp("axxe", "ax*e");
    return 0;
}
