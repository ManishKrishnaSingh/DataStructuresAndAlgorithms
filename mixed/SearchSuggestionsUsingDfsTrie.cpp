#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    bool isLeaf;
    node* children[26];
    node(){
        this->isLeaf = false;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
}Node;

void insertInTrie(Node* root, string iStr){
    Node* pCrawl = root;
    for(int i=0; i<iStr.size(); i++){
        int index = iStr[i]-'a';
        if(pCrawl->children[index] == nullptr){
            pCrawl->children[index] = new Node();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
}

void dfsSearchInTrie(Node* curr, string& word, vector<string>& result){
    // max 3 hints needed
    if(result.size() < 3){
        // prefix is word
        if (curr->isLeaf){
            result.push_back(word);
        }

        // run dfs on all possible paths
        for(int index=0; index<26; index++){
            if (curr->children[index]){
                word += (char)('a'+index); //append the character
                dfsSearchInTrie(curr->children[index], word, result);
                word.pop_back(); //remove last character from string
            }
        }
    }
}

vector<string> searchInTrie(Node* root, string prefix){
    vector<string> result;

    Node *pCrawl = root;
    //find the leaf node for prefix
    for(int i=0;i<prefix.size();++i){
        int index = prefix[i]-'a';
        if (!pCrawl->children[index]){
            return result;
        }
        pCrawl = pCrawl->children[index];
    }

    // dfs search in Trie with given node
    dfsSearchInTrie(pCrawl, prefix, result);

    return result;
}

void searchPrefixSuggestions(vector<string> dictionary, string iStr){
    Node* root = new Node();
    //build Trie with dictionary
    for(auto word : dictionary){
        insertInTrie(root, word);
    }

    string prefix = "";
    for(int i=0; i<iStr.size(); i++){
        prefix = iStr.substr(0,i+1);
        auto hints = searchInTrie(root,prefix);
        
        //print hints for given prefix
        cout<<"\nHints["<<prefix<<"]= ";
        for(auto hint : hints){
            cout<<hint<<";";
        }
    }
}

int main() {
    vector<string> dictionary = {
        "mobile","mouse","moneypot","monitor","mousepad"
    };

    searchPrefixSuggestions(dictionary, "mouse");

    return 0;
}