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

void MorrisPreOrderTraversal(Node* root){
    cout<<"Tree [PreOrder]: ";
    if (root != nullptr){
        Node* prev;
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                cout<<curr->data<<" ";
                curr = curr->right;
            } else {
                prev = curr->left; //in order predecessor
                while (prev->right != nullptr && prev->right != curr){
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    cout<<curr->data<<" ";
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    MorrisPreOrderTraversal(root);

    return 0;
}

