#include <bits/stdc++.h>

using namespace std;

int findCount(int n, int bCount, int cCount){
    if (bCount<0 || cCount<0){
        return 0;
    }
    if (n==0 || (bCount==0 && cCount==0)){
        return 1;
    }

    int res = 0;
    res += findCount(n-1, bCount, cCount);
    res += findCount(n-1, bCount-1, cCount);
    res += findCount(n-1, bCount, cCount-1);

    return res;
}

int stringCountUtil(int dp[][2][3], int n, int bCount, int cCount){
    if (bCount<0 || cCount<0){
        return 0;
    }
    if (n==0 || (bCount==0 && cCount==0)){
        return 1;
    }

    if(dp[n][bCount][cCount] != -1){
        return dp[n][bCount][cCount];
    }

    int res = 0;
    res += stringCountUtil(dp, n-1, bCount, cCount);
    res += stringCountUtil(dp, n-1, bCount-1, cCount);
    res += stringCountUtil(dp, n-1, bCount, cCount-1);

    return (dp[n][bCount][cCount]=res);
}

int stringCount(int n, int bCount, int cCount){
    int dp[n+1][2][3];
    memset(dp, -1, sizeof(dp));
    return stringCountUtil(dp, n, bCount, cCount);
}

int main(){
    int noOfChars=3;

    int count = findCount(noOfChars,1,2);
    cout<<"String Count = "<<count<<endl;

    int mycount = stringCount(noOfChars,1,2);
    cout<<"String Count = "<<mycount<<endl;

    return 0;
}

