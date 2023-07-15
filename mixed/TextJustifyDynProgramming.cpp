#include <bits/stdc++.h>

using namespace std;

const int LINELENGTH = 20;

vector<string> split(string str)
{
    vector<string> out;

    string word;
    stringstream ss(str);
    while(ss >> word)
    {
        out.push_back(word);
    }

    return out;
}

string buildLeftJustifyLine(vector<string>& words)
{
    string strLine = "";
    int n = words.size();
    if(n > 0)
    {
        strLine = words[0]; // add first word
        for(int index = 1; index < n; index++)
        {
            strLine = strLine+" "+words[index];
        }
    }
    return strLine;
}

string buildMiddleJustifyLine(vector<string>& words)
{
    string strLine = "";
    int n = words.size();
    if(n > 0)
    {
        int allSpaces = LINELENGTH;

        for(auto& word : words)
        {
            allSpaces -= word.length();
        }

        strLine = words[0];

        if(n == 1)
        {
            //add to the right
            while(allSpaces-- > 0)
            {
                strLine += " ";
            }
        }
        else
        {
            int spacesPerWord  = allSpaces / (n-1);
            int spacesLeftover = allSpaces % (n-1);

            int index, spaceToApply;
            for(index = 1; index < n; index++)
            {
                spaceToApply = spacesPerWord;

                if(spacesLeftover-- > 0)
                {
                    spaceToApply++;
                }

                while(spaceToApply-- > 0)
                {
                    strLine += " ";
                }

                strLine += words[index];
            }
        }
    }

    return strLine;
}

void PrintJustifyTextLines(stack<pair<int,int>>& stkIndexRange, vector<string>& words)
{
    int left, right, index;
    vector<string> wordsInLine;
    while(stkIndexRange.size())
    {
        wordsInLine.clear();

        left  = stkIndexRange.top().first;
        right = stkIndexRange.top().second;
        
        stkIndexRange.pop(); // remove from stack

        for(index=left; index<right; index++)
        {
            wordsInLine.push_back(words[index]);
        }

        if(stkIndexRange.size() == 0)
        {
            cout<<"["<<buildLeftJustifyLine(wordsInLine)<<"]\n";
        }
        else
        {
            cout<<"["<<buildMiddleJustifyLine(wordsInLine)<<"]\n";
        }
    }
}

void justifyText(string str)
{
    if(!str.empty())
    {
        auto words = split(str);

        int n = words.size();

        int i, j, wLength[n];
        for (i = 0; i < n; i++)
        {
            wLength[i] = words[i].length();
        }

        int spaces[n+1][n+1];

        // find extra spaces
        for(i = 1; i <= n; i++)
        {
            spaces[i][i] = LINELENGTH - wLength[i-1];
            for(j = i+1; j <= n; j++)
            {
                spaces[i][j] = spaces[i][j-1] - wLength[j-1] - 1;
            }
        }

        // update cost matrix
        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                if (spaces[i][j] < 0)
                {
                    spaces[i][j] = INT_MAX;
                }
                else if(j == n) // last line
                {
                    spaces[i][j] = 0;
                }
                else
                {
                    spaces[i][j] = pow(spaces[i][j], 3);
                }
            }
        }

        int solution[n+1];
        int linecost[n+1];

        linecost[0] = 0;
        for(j = 1; j <= n; j++)
        {
            linecost[j] = INT_MAX;
            for(i = 1; i <= j; i++)
            {
                if (linecost[i-1] == INT_MAX || spaces[i][j] == INT_MAX)
                {
                    continue;
                }
                else if(linecost[i-1] + spaces[i][j] < linecost[j])
                {
                    solution[j] = i;
                    linecost[j] = linecost[i-1] + spaces[i][j];
                }
            }
        }

        stack<pair<int, int>> stkIndexRange;
        int index = n;
        while (index > 0)
        {
            stkIndexRange.push({solution[index]-1, index});
            index = solution[index]-1; // update the index
        }

        PrintJustifyTextLines(stkIndexRange, words);
    }
}

int main()
{
    string str = "Consanguineous. Science is what we understand well enough to explain to a computer. Art is everything else we do.";

    justifyText(str);

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N^2)
*************************/
