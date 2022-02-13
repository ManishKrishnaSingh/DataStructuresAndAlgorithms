#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
    node(int key){
        this->data = key;
        this->left = this->right = nullptr;
    }
}Node;

void binaryTreeToDLL(Node *root, Node **head){
    if(root != nullptr) {
        static Node* prev = nullptr;
        // convert left subtree
        binaryTreeToDLL(root->left, head);
        // convert this node
        if (prev == nullptr){
            *head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        // convert right subtree
        binaryTreeToDLL(root->right, head);
    }
}

void PrintList(Node *node){
    cout<<"DLL:";
    Node* curr = node;
    while(curr!=nullptr){
        cout<<" "<<curr->data;
        curr = curr->right;
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head = nullptr;//head
    binaryTreeToDLL(root, &head);
    PrintList(head); //Print DLL

    return 0;
}

