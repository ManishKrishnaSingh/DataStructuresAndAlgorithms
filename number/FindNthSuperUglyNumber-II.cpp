#include <bits/stdc++.h>

using namespace std;

int minOf(std::vector<int> nextval)
{
    int n = nextval.size();

    int minimum = nextval[0];
    for(int i=1; i<n; i++)
    {
        minimum = min(minimum, nextval[i]);
    }

    return minimum;
}

int nthSuperUglyNumber(int n, std::vector<int> primes)
{
    int dp[n];
    dp[0] = 1;

    int i, j;
    vector<int> indexes = {0, 0,  0,  0};
    vector<int> nextval = {3, 7, 11, 13};
    for(i = 1; i < n; i++)
    {
        dp[i] = minOf(nextval);
        for(j = 0; j < 4; j++)
        {
            if(dp[i] == nextval[j])
            {
                indexes[j]++; //increase matching index
                nextval[j] = dp[indexes[j]] * primes[j];
            }
        }
    }

    return dp[n-1];
}

int main()
{
    vector<int> primes = {3, 7, 11, 13};

    for(int n = 1; n <= 7; n++)
    {
        int nthSuperUglyNum = nthSuperUglyNumber(n, primes);
        cout << "\nSuper Ugly Number = " << nthSuperUglyNum;
    }

    return 0;
}

// OUTPUT :-

/**********************
 Super Ugly Number = 1
 Super Ugly Number = 3
 Super Ugly Number = 7
 Super Ugly Number = 9
 Super Ugly Number = 11
 Super Ugly Number = 13
 Super Ugly Number = 21
 **********************/
