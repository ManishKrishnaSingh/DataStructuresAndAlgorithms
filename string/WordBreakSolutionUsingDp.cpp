#include <bits/stdc++.h>

using namespace std;

unordered_set<string> dictionary =
{
    "apple", "orange", "i", "icecream", "and", "like", "yellow"
};

bool IsBreakable(string iStr)
{
    int i, j, n=iStr.length();

    bool dp[n+1];
    memset(dp, false, sizeof(dp));

    dp[0] = true;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(dp[j] and dictionary.count(iStr.substr(j, i-j)))
            {
                dp[i] = true;
            }
        }
    }

    return dp[n];
}

int main()
{
    cout<<boolalpha<<IsBreakable("ilikeappleandorange")<<endl;
    cout<<boolalpha<<IsBreakable("ilikeyellowicecream")<<endl;
    return 0;
}
