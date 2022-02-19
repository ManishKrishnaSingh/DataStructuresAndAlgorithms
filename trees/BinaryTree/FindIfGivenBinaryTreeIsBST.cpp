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

bool IsBinarySearchTree(Node* root, Node* &prev){
    if (root!=nullptr){
        if (!IsBinarySearchTree(root->left, prev)){
            return false;
        }

        if (prev != nullptr && root->data <= prev->data){
            return false;
        }

        prev = root;
        return IsBinarySearchTree(root->right, prev);
    }
    return true;
}

bool IsBinarySearchTree(Node *root){
    Node *prev = nullptr;
    return IsBinarySearchTree(root, prev);
}

int main(){
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(8);

    bool IsBST = IsBinarySearchTree(root);
    cout<<"Is Binary Tree a BST? : "<<boolalpha<<IsBST;

    return 0;
}

