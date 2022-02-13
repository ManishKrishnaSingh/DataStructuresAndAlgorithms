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

int height(Node *root){
    if(root==NULL) {
        return 0;
    }
    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight,rightHeight);
}

int width(Node *root, int level){
    if(root!=nullptr){
        if(level==1) {
            return 1;
        } else if(level>1) {
            int leftWidth  = width(root->left,level-1);
            int rightWidth = width(root->right,level-1);
            return leftWidth + rightWidth;
        }
    }
    return 0;
}

int maxWidth(Node *root) {
    int maxWidth=0;
    int h=height(root);
    for(int i=1; i<=h; i++) {
        maxWidth=max(maxWidth, width(root,i));
    }
    return maxWidth;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    cout<<"Max Width = "<<maxWidth(root);

    return 0;
}

