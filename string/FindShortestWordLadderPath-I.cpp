#include <bits/stdc++.h>

using namespace std;

bool IsDifferByOne(string xStr, string yStr){
    int counter = 0;
    int size = min(xStr.size(),yStr.size());

    for(int i=0; i < size; i++){
        if(xStr[i] != yStr[i]){
            counter++;
        }
    }

    if(counter == 1){
        return true;
    }

    return false;
}

void PrintLadder(vector<string>& ladder){
    cout<<"\nWord Ladder:";
    for(auto word : ladder){
        cout<<" -> "<<word;
    }
}

void findShortestWordLadderPath(vector<string>& dictionary,string start,string final){
    if(start == final){
        return;
    }

    // add start and final
    dictionary.push_back(start);
    dictionary.push_back(final);

    map<string,vector<string>> map;

    int n = dictionary.size();
    for(int i=0; i < n; i++){
        for(int j=i+1; j < n; j++){
            if(IsDifferByOne(dictionary[i], dictionary[j])){
                map[dictionary[i]].push_back(dictionary[j]);
                map[dictionary[j]].push_back(dictionary[i]);
            }
        }
    }

    unordered_set<string> visit;
    queue<pair<string,vector<string>>> que;

    visit.insert(start);
    que.push({start,{start}});

    while(!que.empty()){
        auto front = que.front(); que.pop();

        string word = front.first;
        auto ladder = front.second;

        if(word == final){
            PrintLadder(ladder); break;
        }

        for(auto str : map[word]){
            if(visit.find(str) == visit.end()){
                visit.insert(str);
                // copy the curr ladder
                vector<string> temp(ladder);
                // add new word to ladder
                temp.push_back(str);
                // add new ladder to queue
                que.push({str, temp});
            }
        }
    }
}

int main(){
    vector<string> dictionary = {
        "poon", "plee", "same", "poie", "plie", "poin", "plea"
    };

    findShortestWordLadderPath(dictionary, "toon", "plea");

    return 0;
}