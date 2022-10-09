#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    bool isLeaf;
    node* child[26];
    node(){
        this->isLeaf = false;
        for (int i=0; i<26; i++){
            this->child[i] = nullptr;
        }
    }
}TrieNode;

void insert(TrieNode* root, string iKey){
    TrieNode* pCrawl = root;
    for(int i=0; i<iKey.length(); i++){
        int index = iKey[i] - 'a';
        if(!pCrawl->child[index]){
            pCrawl->child[index] = new TrieNode();
        }
        pCrawl = pCrawl->child[index];
    }
    pCrawl->isLeaf = true;
}

bool search(TrieNode* root, string iKey){
    TrieNode* pCrawl = root;
    for(int i=0; i<iKey.length(); i++){
        int index = iKey[i] - 'a';
        if(!pCrawl->child[index]){
            return false;
        }
        pCrawl = pCrawl->child[index];
    }
    return (pCrawl!=nullptr && pCrawl->isLeaf);
}

bool IsBreakable(string iStr, TrieNode* root){
    if(iStr.empty()){
        return true;
    }

    int n = iStr.size();
    string prefix="",suffix="";
    for (int i=1; i<=n; i++){
        prefix = iStr.substr(0, i);
        suffix = iStr.substr(i, n-i);
        if (search(root, prefix) && IsBreakable(suffix,root)){
            return true;
        }
			
    }
    return false;
}

int main(){
    string dictionary[] = {
        "apple","orange","i","icecream","and","like","yellow"
    };

    TrieNode* trie = new TrieNode();
    //add dictionary words to trie
    for(string word : dictionary){
        insert(trie, word);
    }

    cout<<IsBreakable("ilikeappleandorange", trie)<<endl;
    cout<<IsBreakable("ilikeyellowicecream", trie)<<endl;

    return 0;
}
