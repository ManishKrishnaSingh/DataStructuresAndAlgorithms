#include <bits/stdc++.h>

using namespace std;

/**********************************************
 I/P: digits[] = "121"
 O/P: 3 [Possible Decodings: "ABA", "AU", "LA"]
 **********************************************/

int findPossibleWaysOfDecoding(string& digits){
    int n=digits.size();

    //"0123"->return 0
    if(digits[0]=='0'){
        return 0;
    }

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){
        if (digits[i-1] > '0'){
            dp[i] = dp[i-1];
        }
        if (digits[i-2]=='1' || (digits[i-2]=='2' && digits[i-1]<'7')){
            dp[i] += dp[i-2];
        }
    }

    return dp[n];
}

int main(){
    string digits="121325";
    int nWays=findPossibleWaysOfDecoding(digits);
    cout<<"Possible Ways Of Decoding = "<<nWays;
    return 0;
}

