#include <iostream>

using namespace std;

typedef struct node {
    int frequency;
    node* children[26];
    node(){
        frequency = 1;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
}Node;

void insert(Node* node, string word){
    Node* pCrawl = node;
    for(int i=0; i<word.size(); i++){
        int idx = word[i]-'a';
        if(pCrawl->children[idx] == nullptr){
            pCrawl->children[idx] = new Node();
        } else {
            (pCrawl->children[idx]->frequency)++;
        }
        pCrawl = pCrawl->children[idx];
    }
}

Node* createTrie(string words[], int n){
    Node* root = new Node();
    root->frequency = 0;

    for(int i=0; i<n; i++){
        insert(root, words[i]);
    }

    return root;
}

void findUniquePrefixes(Node* node, string str){
    if(node==nullptr){
        return;
    }

    if(node->frequency==1){
        cout<<str<<" ";
    } else {
        for(int i=0; i<26; i++){
            if(node->children[i]){
                char c = i+'a';
                findUniquePrefixes(node->children[i], str+c);
            }
        }
    }
}

int main(){
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = createTrie(arr, n);

    findUniquePrefixes(root, "");

    return 0;
}

