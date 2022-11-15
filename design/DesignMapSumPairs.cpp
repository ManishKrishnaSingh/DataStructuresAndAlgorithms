#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int score;
    TrieNode* children[26];
    TrieNode(){
        this->score = 0;
        for(int i=0; i<26; i++){
            this->children[i] = nullptr;
        }
    }
};

class MapSum {
    TrieNode* root;
    unordered_map<string,int> map;

  public:
    MapSum(){
        this->root = new TrieNode();
    }

    void insert(string key, int value){
        TrieNode* curr = root;
        // find delta to update
        int diff = value-map[key];
        for (char ch : key){
            int index = (ch-'a');
            if (curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->score = curr->score + diff;
        }
        map[key] = value; // update hash with key-value
    }

    int sum(string prefix){
        TrieNode* curr = root;
        for (char ch : prefix){
            int index = (ch - 'a');
            if(curr->children[index] == nullptr){
                return 0;
            }
            curr = curr->children[index];
        }
        return curr->score;
    }
};

int main(){
    cout<<"Map Sum"<<endl;

    MapSum mapSum;

    mapSum.insert("apple",3);
    cout<<"\nSum = "<<mapSum.sum("ap");

    mapSum.insert("app", 2);
    cout<<"\nSum = "<<mapSum.sum("ap");

    return 0;
}