#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *left;
    node *right;
    node(int key){
        this->data = key;
        this->left=this->right=nullptr;
    }
}Node;

int convertToSumTree(Node* node){
    if(node == nullptr){
        return 0;
    }

    int data = node->data;
    node->data = convertToSumTree(node->left) + convertToSumTree(node->right);

    return data + node->data;
}

void InOrderTraversal(Node* node){
    if(node != nullptr){
        InOrderTraversal(node->left);
        cout<<" "<<node->data;
        InOrderTraversal(node->right);
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    convertToSumTree(root);

    cout<<"Tree [InOrder]:";
    InOrderTraversal(root);

    return 0;
}

