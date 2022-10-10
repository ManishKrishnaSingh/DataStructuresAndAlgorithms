#include <bits/stdc++.h>

using namespace std;

/** map contains pair <word, value> */
unordered_map<string,int> dictionary={
    {"cats", 4}, {"cat", 5}, {"and", 1}, {"sand", 5}, {"dog", 8}
};

vector<string> split(string iStr){
    vector<string> list;
    string line;
    stringstream ss(iStr);
    while(getline(ss, line, ' ')){
        list.push_back(line);
    }
    return list;
}

bool IsValidWord(string iStr){
    if(dictionary.find(iStr)!=dictionary.end()){
        return true;
    }
    return false;
}

pair<string,int> maximumScoreWordBreak(string iStr){
    vector<string> vec;
    int n = iStr.length();

    // store word with index
    vector<vector<string>> dp(n);
    for(int i=0; i<n; i++){
        vec.clear();
        for(int j = i+1; j<n+1; j++){
            if(IsValidWord(iStr.substr(i,j-i))){
                vec.push_back(iStr.substr(i,j-i));
            }
        }
        dp[i] = vec;
    }

    // bottom-up approch form solution   
    vector<vector<string>> solution(n);
    for(int i=n-1; i>=0; i--){
        vec.clear();
        if (dp[i].size()) {
            for(auto word : dp[i]){
                int wLen = word.length();
                // if word is last word
                if(i+wLen == n){
                    vec.push_back(word);
                } else if(solution[i+wLen].size()){
                    for(auto wstr : solution[i+wLen]){
                        vec.push_back(word+" "+wstr);
                    }
                }
            }
        }
        solution[i] = vec;
    }

    // return solution
    string strSolution="";
    int currScore,maxScore=0;
    for(string line : solution[0]){
        currScore = 0;
        //calculate cost to form line
        for(string word : split(line)){
            currScore+=dictionary[word];
        }

        //update line & maxScore
        if(currScore > maxScore){
            strSolution = line;
            maxScore = currScore;
        }
	}

	return {strSolution, maxScore};
}

int main(){
    string str = "catsanddog";
    auto res = maximumScoreWordBreak(str);
    cout<<"Score["<<res.first<<"]="<<res.second;

    return 0;
}