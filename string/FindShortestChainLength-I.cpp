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

int shortestChainLength(vector<string>& dictionary,string start,string final){
    if(start == final){
        return 0;
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

    queue<pair<string,int>> que;
    unordered_set<string> visit;

    que.push({start,1});
    visit.insert(start);

    while(!que.empty()){
        auto front = que.front(); que.pop();

        string word  = front.first;
        int distance = front.second;
        if(word == final){
            return distance;
        }

        for(auto str : map[word]){
            if(visit.find(str) == visit.end()){
                visit.insert(str);
                que.push({str, distance+1});
            }
        }
    }

    return 0;
}

int main(){
    vector<string> dictionary = {
        "poon", "plee", "same", "poie", "plie", "poin", "plea"
    };

    cout<<"Length [WL] = "<<shortestChainLength(dictionary, "toon", "plea");

    return 0;
}
