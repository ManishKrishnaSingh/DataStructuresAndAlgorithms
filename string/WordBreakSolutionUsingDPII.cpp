#include <bits/stdc++.h>

using namespace std;

unordered_set<string> dictionary = {
    "apple", "orange", "i", "icecream", "and", "like", "yellow"
};

bool IsBreakable(string iStr){
    int n = iStr.length();

    bool dp[n+1];
    memset(dp, false, sizeof(dp));

    dp[0] = true;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(dp[j] and dictionary.find(iStr.substr(j, i-j)) != dictionary.end())
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main(){
    cout<<boolalpha<<IsBreakable("ilikeappleandorange")<<endl;
    cout<<boolalpha<<IsBreakable("ilikeyellowicecream")<<endl;

    return 0;
}
