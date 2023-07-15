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

void justifyText(string str)
{
    vector<string> words = split(str);

    vector<vector<string>> lines;
	
    int currLineLength = 0;
    vector<string> currWords;
    for(auto& word : words)
    {
        currWords.push_back(word);

        // update line length
        if(currWords.size() == 1)
        {
            currLineLength = word.length();
        }
        else
        {
            currLineLength += (word.length() + 1) ;
        }

        if(currLineLength > LINELENGTH)
        {
            // pop last word
            currWords.pop_back();
            // add to the line list
            lines.push_back(currWords);

            // reset list
            currWords.clear();
            // add back current word
            currWords.push_back(word);
            // update current line length
            currLineLength = word.length();
        }
        else if(currLineLength == LINELENGTH)
        {
            // add to the line list
            lines.push_back(currWords);
            // reset line length and clear list
            currLineLength = 0; currWords.clear();
        }
    }

    // add last line
    if(currWords.size())
    {
        lines.push_back(currWords);
    }

    // Print Justified TextLines
    int counter=0, n=lines.size();
    for(auto& wordsInLine : lines)
    {
        counter++;

        if(counter == n)
        {
            cout<<"["<<buildLeftJustifyLine(wordsInLine)<<"]\n";
        }
        else
        {
            cout<<"["<<buildMiddleJustifyLine(wordsInLine)<<"]\n";
        }
    }
}

int main()
{
    string str = "Science is what we understand well enough to explain to a computer. Art is everything else we do.";

    justifyText(str);

    return 0;
}

/**********************
Time Complexity  : O(N)
Space Complexity : O(N)
***********************/
