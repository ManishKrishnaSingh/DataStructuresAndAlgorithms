#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int value;
    node *left, *right;
    node(int iValue){
        this->value = iValue;
        this->left = this->right = nullptr;
    }
}Node;

/**pair {inclRoot, exclRoot}*/
pair<int,int> dfs(Node* root){
    if(root==nullptr){
        return {0, 0};
    }

    auto left  = dfs(root->left);
    auto right = dfs(root->right);
    
    int inclRoot = root->value + left.second + right.second;
    int exclRoot = max(left.first,left.second) + max(right.first,right.second);

    return {inclRoot, exclRoot};
}

int maxRob(Node* root){
    auto pair = dfs(root);
    return max(pair.first, pair.second);
}

int main(){
    Node* root1 = new Node(3);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(3);
    root1->right->right = new Node(1);
    cout<<"\nMax Rob = "<<maxRob(root1);

    Node* root2 = new Node(3);
    root2->left = new Node(4);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right->right = new Node(1);
    cout<<"\nMax Rob = "<<maxRob(root2);

    return 0;
}