#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int key;
    node *left, *right, *next;
    node(int iKey){
        this->key = iKey;
        this->left = this->right = this->next = nullptr;
    }
}Node;

class BSTIterator {
    stack<Node*> stk;

  public:
    BSTIterator(Node* root){
        pushToLeft(root);
    }

    bool hasNext(){
        if(stk.empty()){
            return false;
        }
        return true;
    }

    int next(){
        Node* node = stk.top();
        stk.pop();

        pushToLeft(node->right);
        return node->key;
    }

    void pushToLeft(Node* node){
        if (node != nullptr){
            stk.push(node);
            pushToLeft(node->left);
        }
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout<<"Binary Search Tree Iterator:";
    BSTIterator *iter = new BSTIterator(root);
    while(iter->hasNext()){
        cout<<" "<<iter->next();
    }

    return 0;
}