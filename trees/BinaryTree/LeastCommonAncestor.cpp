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

int findLCA(Node* node, int x, int y){
    if(x > y){
        return findLCA(node, y, x);
    }
    if(node != nullptr){
        if(x < node->data && y < node->data){
            return findLCA(node->left, x, y);
        } else if(x > node->data && y > node->data){
            return findLCA(node->right, x, y);
        } else {
            return node->data;
        }
    }
    return -1;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    int x = 5, y = 9;
    cout<<"LCA [X,Y] = "<<findLCA(root, x, y)<<endl;

    return 0;
}

