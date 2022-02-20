#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> dictionary {
    "poon", "plee", "same", "poie", "plie", "poin", "plea"
};

vector<string> findNextWords(string word){
    vector<string> nextWords;
    for(int i=0; i<word.size(); i++) {
        char s = word[i];
        for(char c='a'; c<='z'; c++) {
            word[i] = c;
            if (dictionary.count(word)){
                nextWords.push_back(word);
            }
        }
        word[i] = s;
    }
    return nextWords;
}

void findWordLadders(string start, string final){
    bool IsLadderComplete = false;
    vector<vector<string>> listLadder;

    queue<vector<string>> qShortestPath;
    qShortestPath.push({ start });

    while (!qShortestPath.empty()) {
        int size = qShortestPath.size();
        for(int i=0; i<size; i++) {
            vector<string> curr = qShortestPath.front();
            qShortestPath.pop();

            vector<string> nextWords = findNextWords(curr.back());
            for(int j=0; j<nextWords.size(); j++) {
                vector<string> newLadder(curr.begin(), curr.end());
                newLadder.push_back(nextWords[j]);
                if (nextWords[j] == final) {
                    IsLadderComplete = true;
                    listLadder.push_back(newLadder);
                }
                qShortestPath.push(newLadder);
            }
        }
        if (IsLadderComplete) break;
    }

    // Print Word Ladders
    for(int i=0; i<listLadder.size(); i++) {
        cout<<"["<<i+1<<"] :";
        for(int j=0; j<listLadder[i].size(); j++) {
            cout<<" -> "<<listLadder[i][j];
        }
        cout<<endl;
    }
}

int main(){
    string start="toon",final="plea";
    findWordLadders(start, final);
    return 0;
}

