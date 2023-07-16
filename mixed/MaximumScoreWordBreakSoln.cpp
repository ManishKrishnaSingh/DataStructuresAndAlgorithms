#include <bits/stdc++.h>

using namespace std;


/** map contains pair <word, value> */
unordered_map<string,int> dictionary =
{
    {"cats", 4}, {"cat", 5}, {"and", 1}, {"sand", 5}, {"dog", 8}
};


vector<string> split(string str)
{
    vector<string> list;

    string line;
    stringstream ss(str);
    while(getline(ss, line, ' '))
    {
        list.push_back(line);
    }

    return list;
}

bool IsValidWord(string str)
{
    if(dictionary.count(str))
    {
        return true;
    }
    return false;
}


pair<string,int> findMaximumScoreOnWordBreak(string str)
{
    int i, j, n=str.length();

    // store word with index
    vector<vector<string>> dp(n);

    vector<string> words;
    for(i = 0; i < n; i++)
    {
        words.clear();

        for(j = i+1; j < n+1; j++)
        {
            if(IsValidWord(str.substr(i, j-i)))
            {
                words.push_back(str.substr(i, j-i));
            }
        }

        dp[i] = words;
    }


    // bottom-up approch form solution   
    vector<vector<string>> solution(n);
    for(i = n-1; i >= 0; i--)
    {
        words.clear();

        for(auto& word : dp[i])
        {
                int wLen = word.length();

                // if word is last word
                if(i+wLen == n)
                {
                    words.push_back(word);
                }
                else if(solution[i+wLen].size())
                {
                    for(auto& strWord : solution[i+wLen])
                    {
                        words.push_back(word + " " + strWord);
                    }
                }
        }

        solution[i] = words;
    }


    // return the solution
    string strSolution="";
    int currScore, maxScore=0;
    for(string& line : solution[0])
    {
        currScore = 0;

        // calculate cost to form line
        for(string& word : split(line))
        {
            currScore += dictionary[word];
        }

        // update line+maxScore
        if(currScore > maxScore)
        {
            strSolution = line;
            maxScore = currScore;
        }
	}

	return {strSolution, maxScore};
}


int main()
{
    string str = "catsanddog";

    auto res = findMaximumScoreOnWordBreak(str);
    cout<<"Score ["<<res.first<<"] = "<<res.second;

    return 0;
}
