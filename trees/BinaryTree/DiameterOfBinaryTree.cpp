#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *left, *right;
    node(int iKey){
        data = iKey;
        left = right = nullptr;
    }
}Node;

int maxOf(int x, int y, int z){
    return max(x, max(y,z));
}

int findHeight(Node* node){
    if(node == nullptr){
        return 0;
    }

    int heightLeft =findHeight(node->left);
    int heightRight=findHeight(node->right);

    return 1 + max(heightLeft, heightRight);
}

int diameterOfBinaryTree(Node* node){
    if(node==nullptr){
        return 0;
    }

    int heightLeft  = findHeight(node->left);
    int heightRight = findHeight(node->right);

    int diameterLeft  = diameterOfBinaryTree(node->left);
    int diameterRight = diameterOfBinaryTree(node->right);

    return maxOf(diameterLeft, diameterRight, (1+heightLeft+heightRight));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(0);
    root->right->right = new Node(5);

    int diameter = diameterOfBinaryTree(root);
    cout<<"Diameter [Binary Tree] = "<<diameter;

    return 0;
}

