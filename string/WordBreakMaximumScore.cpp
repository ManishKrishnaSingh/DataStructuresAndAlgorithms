#include <bits/stdc++.h>

using namespace std;


unordered_map<string, int> dictionary =
{
    {"h", 1}, {"e", 2}, {"ello", 5}, {"hello", 10}, {"world", 10}
};


int rcWordBreakScore(string iStr)
{
    if(iStr.empty())
	{
        return 0;
    }

    int maxScore = INT_MIN;
    for(int i=1; i<=iStr.size(); i++)
    {
        string word = iStr.substr(0,i);
        if(dictionary.find(word) != dictionary.end())
        {
            int currScore=dictionary[word]+rcWordBreakScore(iStr.substr(i));
            maxScore = max(maxScore, currScore);
        }
    }
    return maxScore;
}


int dpWordBreakScore(string iStr)
{
    int i, j, n=iStr.length();

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    string strWord = "";
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < i; j++)
        {
            strWord = iStr.substr(j,i-j);
            if (dictionary.count(strWord))
            {
                dp[i] = max(dp[i], dp[j] + dictionary[strWord]);
            }
        }
    }

    return dp[n];
}


int main() {
    string str = "helloworld";

    int bfScore = rcWordBreakScore(str);
    cout<<"Word Break Score [RC] = "<<bfScore<<endl;

    int dpScore = dpWordBreakScore(str);
    cout<<"Word Break Score [DP] = "<<dpScore<<endl;

    return 0;
}

