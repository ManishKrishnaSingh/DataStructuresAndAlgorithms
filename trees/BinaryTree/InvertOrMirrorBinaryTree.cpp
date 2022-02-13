#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
    node(int key){
        data = key;
        left = right = nullptr;
    }
}Node;

void inOrder(Node* node){
    if(node != nullptr){
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
}

void mirror(Node* node){
    if(node != nullptr){
        mirror(node->left);
        mirror(node->right);
        //swap left and right nodes
        swap(node->left, node->right);
    }
}

int main(){
    cout<<"Mirror Tree :=>"<<endl;

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    cout<<"Tree:";
    inOrder(root);

    mirror(root);

    cout<<"\nTree:";
    inOrder(root);

    return 0;
}

