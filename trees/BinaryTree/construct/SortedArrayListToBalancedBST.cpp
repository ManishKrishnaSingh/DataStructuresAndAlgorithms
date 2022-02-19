#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left, *right;
    node(int value){
        this->data = value;
        left = right = nullptr;
    }
}Node;

void printInOder(Node* node){
    if(node != nullptr){
        printInOder(node->left);
        cout<<node->data<<" ";
        printInOder(node->right);
    }
}

void printPreOder(Node* node){
    if(node != nullptr){
        cout<<node->data<<" ";
        printPreOder(node->left);
        printPreOder(node->right);
    }
}

Node* arrayToBST(int arr[], int low, int high){
    if(low > high){
        return nullptr;
    }
    int mid = (low+high)>>1;
    Node *node = new Node(arr[mid]);
    node->left = arrayToBST(arr, low, mid-1);
    node->right = arrayToBST(arr, mid+1, high);
    return node;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = arrayToBST(arr, 0, n-1);

    cout << "In Order [BST]: ";
    printInOder(root);
    cout << "\nPreOrder [BST]: ";
    printPreOder(root);

    return 0;
}

