#include <map>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int shortestChainLen(string start, string final, set<string>& D){
    if(start == final){
        return 0;
    }

    map<string, vector<string>> umap;
    for(int i = 0; i < start.size(); i++){
        string str = start.substr(0,i) + "*" + start.substr(i+1);
        umap[str].push_back(start);
    }

    for(auto it = D.begin(); it != D.end(); it++){
        string word = *it;
        for(int j = 0; j < word.size(); j++){
            string str = word.substr(0,j) + "*" + word.substr(j+1);
            umap[str].push_back(word);
        }
    }

    queue<pair<string, int>> q;
    map<string, int> visited;

    q.push(make_pair(start,1));
    visited[start] = 1;

    while(!q.empty()){
        pair<string, int> p = q.front();
        q.pop();

        string word = p.first;
        int dist = p.second;

        if(word == final){
            return dist;
        }

        for(int i = 0; i < word.size(); i++){
            string str = word.substr(0,i) + "*" + word.substr(i+1);

            vector<string> vect = umap[str];
            for(int j = 0; j < vect.size(); j++){
                if(visited[vect[j]] == 0){
                    visited[vect[j]] = 1;
                    q.push(make_pair(vect[j], dist + 1));
                }
            }
        }
    }
    return 0;
}

int main(){
    set<string> D;

    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");

    string start = "toon";
    string final = "plea";

    cout<<"Length [WL] = "<<shortestChainLen(start, final, D);

    return 0;
}

