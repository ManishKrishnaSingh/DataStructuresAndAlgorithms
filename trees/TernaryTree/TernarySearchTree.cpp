#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    char data;
    bool IsEndOfWord;
    node *left, *center, *right;
    node(char iChar){
        this->data = iChar;
        this->IsEndOfWord = false;
        this->left = this->center = this->right = nullptr;
    }
}Node;

Node* insert(Node* root, char* word){
    if(root == nullptr){
        root = new Node(*word);
    }

    if((*word) < root->data)
    {
        root->left = insert(root->left, word);
    }
    else if((*word) > root->data)
    {
        root->right = insert(root->right, word);
    }
    else
    {
        if(*(word+1))
        {
            root->center = insert(root->center, word+1);
        }
        else
        {
            root->IsEndOfWord = true;
        }
    }
	return root;
}

bool search(Node* root, char* word){
    if(root == nullptr){
        return false;
    }

    if((*word) < root->data)
    {
        return search(root->left, word);
    }
    else if((*word) > root->data)
    {
        return search(root->right, word);
    }
    else
    {
        if(*(word+1) == '\0')
        {
            return root->IsEndOfWord;
        }
        else
        {
            return search(root->center, word+1);
        }
    }
}

int main(){
    Node* dictionary = nullptr;

    char boo[] = "boo";
    char cat[] = "cat";
    char caa[] = "caa";
    char bat[] = "bat";
    char bun[] = "bun";
    char foo[] = "foo";

    dictionary = insert(dictionary, boo);
    dictionary = insert(dictionary, cat);
    dictionary = insert(dictionary, caa);
    dictionary = insert(dictionary, bat);
    dictionary = insert(dictionary, bun);

    cout<<"Search['boo'] => "<<search(dictionary, boo)<<endl;
    cout<<"Search['foo'] => "<<search(dictionary, foo)<<endl;
    cout<<"Search['cat'] => "<<search(dictionary, cat)<<endl;
    cout<<"Search['bat'] => "<<search(dictionary, bat)<<endl;
    cout<<"Search['caa'] => "<<search(dictionary, caa)<<endl;

    return 0;
}