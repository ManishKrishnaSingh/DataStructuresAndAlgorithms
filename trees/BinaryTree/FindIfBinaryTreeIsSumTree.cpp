#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
    node(int key){
        data = key;
        left = right = nullptr;
    }
}Node;

bool IsLeaf(node *node){
    if(node != nullptr && node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

bool IsSumTree(node* node){
    if(node==nullptr || IsLeaf(node)){
        return true;
    }
    if(IsSumTree(node->left) && IsSumTree(node->right)){
        int sumLeft, sumRight;
        // Left Sub Tree
        if(node->left==nullptr){
            sumLeft = 0;
        } else if(IsLeaf(node->left)){
            sumLeft = node->left->data;
        } else {
            sumLeft = 2*(node->left->data);
        }
        // Right Sub Tree
        if(node->right==nullptr){
            sumRight = 0;
        } else if(IsLeaf(node->right)){
            sumRight = node->right->data;
        } else {
            sumRight = 2*(node->right->data);
        }
        return (node->data == sumLeft+sumRight);
    }
    return false;
}

int main(){
    Node* root = new Node(26);

    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    cout<<"Is SumTree = "<<boolalpha<<IsSumTree(root);

    return 0;
}

