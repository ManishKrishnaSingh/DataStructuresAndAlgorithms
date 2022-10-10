#include <bits/stdc++.h>

using namespace std;

/** map contains pair <word, value> */
unordered_map<string,int> dictionary={
    {"sam", 4}, {"sung", 5}, {"i", 1}, {"like", 6}, {"samsung", 8}
};

bool IsValidWord(string iStr){
    if(dictionary.find(iStr)!=dictionary.end()){
        return true;
    }
    return false;
}

string buildString(vector<string>& v){
    string str = "";
    if(v.size() > 0){
        str = v[0];
        for(int i=1; i<v.size(); i++){
            str += " " + v[i];
        }
    }
    return str;
}

void solveWordBreak(string iStr,vector<string>& words, vector<vector<string>>& oSolutions){
    if(iStr.empty()){
        //add to the solution list
        oSolutions.push_back(words);
    } else {
        //search substr & call recursive
        for(int i=0; i<iStr.size(); i++){
            if(IsValidWord(iStr.substr(0,i+1))){
                words.push_back(iStr.substr(0,i+1)); //append word
                solveWordBreak(iStr.substr(i+1), words, oSolutions);
                words.pop_back(); // remove the last inserted word
            }
        }
    }
}

pair<string,int> findMaximumScoreWordBreak(string iStr){
    vector<string> words;
    vector<vector<string>> solutions;
    //all possible solutions of word break
    solveWordBreak(iStr, words, solutions);
    
    string strSolution="";
    int currScore,maxScore=INT_MIN;
    if(solutions.size() > 0){
        // find solution with max score
        for(auto solution: solutions){
            currScore = 0;
            for(string word : solution){
                currScore += dictionary[word];
            }
            if(currScore > maxScore){
                 maxScore = currScore;
                 strSolution = buildString(solution);
            }
        }
    }

    return make_pair(strSolution, maxScore);
}

int main() {
    string aStr="ilikesamsung";
    auto res = findMaximumScoreWordBreak(aStr);
    cout<<"Score["<<res.first<<"]="<<res.second;

    return 0;
}