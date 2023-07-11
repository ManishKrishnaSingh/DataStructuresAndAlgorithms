#include <bits/stdc++.h>

using namespace std;

/********************************************************************
Given a length n, count the number of strings of length n that can be
made using 'a', 'b' and 'c' with at most one 'b' and two 'c's allowed
*********************************************************************/

int findCount(int n, int bCount, int cCount)
{
    if (bCount<0 || cCount<0)
    {
        return 0;
    }

    if (n==0 || (bCount==0 && cCount==0))
    {
        return 1;
    }

    int counter = 0;
    counter += findCount(n-1, bCount, cCount);
    counter += findCount(n-1, bCount-1, cCount);
    counter += findCount(n-1, bCount, cCount-1);

    return counter;
}


int dpFindCountUtil(int dp[][2][3], int n, int bCount, int cCount)
{
    if (bCount<0 || cCount<0)
    {
        return 0;
    }

    if (n==0 || (bCount==0 && cCount==0))
    {
        return 1;
    }

    if(dp[n][bCount][cCount] != -1)
    {
        return dp[n][bCount][cCount];
    }

    int counter = 0;
    counter += dpFindCountUtil(dp, n-1, bCount, cCount);
    counter += dpFindCountUtil(dp, n-1, bCount-1, cCount);
    counter += dpFindCountUtil(dp, n-1, bCount, cCount-1);

    return dp[n][bCount][cCount] = counter;
}

int dpFindCount(int n, int bCount, int cCount)
{
    int dp[n+1][2][3];
    memset(dp, -1, sizeof(dp));
    return dpFindCountUtil(dp, n, bCount, cCount);
}


int main(){
    int noOfChars=3;

    int rcCount = findCount(noOfChars,1,2);
    cout<<"String Count = "<<rcCount<<endl;

    int dpCount = dpFindCount(noOfChars,1,2);
    cout<<"String Count = "<<dpCount<<endl;

    return 0;
}

/************************
Recursive Method:
Time Complexity  : O(3^N)
Space Complexity : O(1)

Dynamic Programming
Time Complexity  : O(N)
Space Complexity : O(N)
*************************/
