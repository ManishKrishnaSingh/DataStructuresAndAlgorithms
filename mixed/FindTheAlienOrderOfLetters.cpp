#include <bits/stdc++.h>

using namespace std;

/** alienOrderOfLettersUtil using "Topological Sort" */
void alienOrderOfLettersUtil(unordered_map<char, vector<char>>& graph, char start, unordered_set<char>& visited, stack<char>& stk){
    visited.insert(start);
    for(char ch : graph[start]){
        if(visited.find(ch) == visited.end()){
            alienOrderOfLettersUtil(graph, ch, visited, stk);
        }
    }
    stk.push(start);
}

void alienOrderOfLetters(vector<string>& dictionary){
    int n = dictionary.size();
    if(n > 0){
        char start;
        int minLen,i,j;
        stack<char> stk;
        unordered_set<char> visited;
        unordered_map<char, vector<char>> graph;

        // first start character
        start = dictionary[0][0];
        string xStr="", yStr="";
        for(i = 0; i < n-1; i++){
            xStr = dictionary[i];
            yStr = dictionary[i+1];
            minLen = min(xStr.length(), yStr.length());
            for(j = 0; j < minLen; j++){
                if(xStr[j] != yStr[j]){
                    // add characters to the graph
                    graph[xStr[j]].push_back(yStr[j]);
                }
            }
        }

        // use topological sort to find order of characters
        alienOrderOfLettersUtil(graph, start, visited, stk);

        cout<<"alien order: ";
        while(!stk.empty()){
            cout<<stk.top()<<"";
            stk.top(); stk.pop();
        }
    }
}

int main() {
    vector<string> dictionary = {
        "wrt", "wrf", "er", "ett", "rftt"
    };

    alienOrderOfLetters(dictionary);

    return 0;
}