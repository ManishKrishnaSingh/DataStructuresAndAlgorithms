#include <climits>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dictionary = {
    {"h", 1}, {"e", 2}, {"ello", 5}, {"hello", 10}, {"world", 10}
};

int rcWordBreakScore(string iStr){
    if(iStr.empty()){
        return 0;
    }
    int maxScore = INT_MIN;
    for(int i=1; i<=iStr.size(); i++){
        string word = iStr.substr(0,i);
        if(dictionary.find(word) != dictionary.end()){
            int currScore=dictionary[word]+rcWordBreakScore(iStr.substr(i));
            maxScore = max(maxScore, currScore);
        }
    }
    return maxScore;
}

int dpWordBreakScore(string iStr) {
    int n = iStr.length();

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if (dictionary.find(iStr.substr(j,i-j)) != dictionary.end()){
                dp[i] = max(dp[i], dp[j]+dictionary[iStr.substr(j, i-j)]);
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

