// https://leetcode.com/problems/student-attendance-record-ii/

#include <bits/stdc++.h>

using namespace std;

int dp[1001][2][3];


int solveRecursive(int n, int A, int L)
{
    if(A >= 2 || L >= 3)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }

    int PR = solveRecursive(n-1, A, 0);
    int AR = solveRecursive(n-1, A+1, 0);
    int LR = solveRecursive(n-1, A, L+1);

    return PR + AR + LR;
}

int checkRecordUsingRecursion(int n)
{
    return solveRecursive(n, 0, 0);
}


int solveTopDown(int n, int A, int L)
{
    if(A >= 2 || L >= 3)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }

    if(dp[n][A][L] != -1)
    {
        return dp[n][A][L];
    }

    int PR = solveTopDown(n-1, A, 0);
    int AR = solveTopDown(n-1, A+1, 0);
    int LR = solveTopDown(n-1, A, L+1);

    return dp[n][A][L] = PR + AR + LR;
}

int checkRecordUsingMemoization(int n)
{
    memset(dp, -1, sizeof dp);
    return solveTopDown(n, 0, 0);
}


int solveBottomUp(int n)
{
    memset(dp, 0, sizeof dp);
    
    int D, A, L, result;

    // Base Case, days == 0
    for(A = 0; A <= 1; A++)
    {
        for(L = 0; L <= 2; L++)
        {
            dp[0][A][L] = 1;
        }
    }

    // Process Bottom Up
    for(D = 1; D <= n; D++)
    {
        for(A = 0; A <= 1; A++)
        {
            for(L = 0; L <= 2; L++)
            {
                result =  dp[D-1][A][0];                    // P
                result += (A+1 <= 1 ? dp[D-1][A+1][0] : 0); // A
                result += (L+1 <= 2 ? dp[D-1][A][L+1] : 0); // L

                dp[D][A][L] = result;
            }
        }
    }

    return dp[n][0][0];
}

int checkRecordUsingTabulation(int n)
{
    return solveBottomUp(n);
}


int main()
{
    cout << "\n Records [ Recursion   ] = " << checkRecordUsingRecursion(2);
    cout << "\n Records [ Memoization ] = " << checkRecordUsingMemoization(2);
    cout << "\n Records [ Tabulation  ] = " << checkRecordUsingTabulation(2);

    return 0;
}
