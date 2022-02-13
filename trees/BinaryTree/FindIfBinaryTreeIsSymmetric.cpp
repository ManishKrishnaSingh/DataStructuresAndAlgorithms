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

bool IsTreeSymmetric(Node* root1, Node* root2){
    if (root1==nullptr && root2==nullptr){
        return true;
    }

    if (root1!=nullptr && root2!=nullptr && root1->data==root2->data){
        return IsTreeSymmetric(root1->left, root2->right) && IsTreeSymmetric(root1->right, root2->left);
    }
    return false;
}

bool IsTreeSymmetric(Node* root){
    return IsTreeSymmetric(root, root);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout<<"Is Binary Tree Symmetric ? "<<boolalpha<<IsTreeSymmetric(root);

    return 0;
}

