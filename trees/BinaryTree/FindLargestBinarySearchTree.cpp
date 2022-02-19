#include <climits>
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

typedef struct info {
    int max;
    int min;
    int btSize;
    int bstSize;
    bool IsBST;
}Info;

Info findLargestBinarySearchTree(Node* root){
    if (root==nullptr){
        return {INT_MIN, INT_MAX, 0, 0, true};
    }
    if (root->left==nullptr && root->right==nullptr){
        return {root->data, root->data, 1, 1, true};
    }

    Info lft = findLargestBinarySearchTree(root->left);
    Info rht = findLargestBinarySearchTree(root->right);

    Info info; //final return object
    info.btSize = (1+lft.btSize+rht.btSize);

    //If whole tree rooted under current root is Binary Search Tree
    if (lft.IsBST && rht.IsBST && lft.max<root->data && rht.min>root->data){
        info.min = min(lft.min, min(rht.min, root->data));
        info.max = max(rht.max, max(lft.max, root->data));
        //update bst data
        info.IsBST = true;
        info.bstSize = info.btSize;
    } else {
        //return max of left and right subtrees
        info.IsBST = false;
        info.bstSize = max(lft.bstSize, rht.bstSize);
    }
    return info;
}

int main(){
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);

    Info info = findLargestBinarySearchTree(root);
    cout<<"Size [Binary Search Tree] = "<<info.bstSize;

    return 0;
}

