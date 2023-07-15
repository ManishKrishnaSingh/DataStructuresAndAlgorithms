#include <bits/stdc++.h>

using namespace std;

bool matches(string txt, string pat)
{
    int i, j;
    int m = txt.length();
    int n = pat.length();

    bool **dp = new bool*[m+1];
    for(i = 0; i <= m; i++)
    {
        dp[i] = new bool [n+1];
        for(j = 0; j <= n; j++)
        {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for(j=1; j<=n; j++)
    {
        if(pat[j-1] == '*')
        {
            dp[0][j] = dp[0][j-2];
        }
    }

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(pat[j-1]=='*')
            {
                dp[i][j] = dp[i][j-2];
                if(pat[j-2]=='.' || pat[j-2]==txt[i-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
            else if(pat[j-1]=='.' || pat[j-1]==txt[i-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}

int main()
{
    cout<<"Is Regex Match = "<<boolalpha<<matches("axxe", "ax*e");

    return 0;
}

/************************
Time Complexity  : O(M*N)
Space Complexity : O(M*N)
*************************/