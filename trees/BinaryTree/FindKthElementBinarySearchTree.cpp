#include <climits>
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

int findKthSmallest(Node *root, int K){
    int kthSmallest = INT_MIN;

    int count = 0;
    Node *curr = root;
    while (curr != nullptr){
        if (curr->left == nullptr){
            if (++count==K){
                kthSmallest = curr->data;
            }
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
            if (prev->right==NULL){
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                if (++count==K){
                    kthSmallest = curr->data;
                }
                curr = curr->right;
            }
        }
    }
    return kthSmallest;
}

int findKthLargest(Node* root, int K){
    int kthLargest = INT_MAX;

    int count = 0;
    Node* curr = root;
    while (curr != NULL) {
        if (curr->right == NULL) {
            if (++count == K){
                kthLargest = curr->data;
            }
            curr = curr->left;
        } else {
            Node* succ = curr->right;
            while (succ->left != NULL && succ->left != curr){
                succ = succ->left;
            }
            if (succ->left == NULL) {
                succ->left = curr;
                curr = curr->right;
            } else {
                succ->left = NULL;
                if (++count ==K){
                    kthLargest = curr->data;
                }
                curr = curr->left;
            }
        }
    }
    return kthLargest;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    cout<<"Kth Largest  [3] = "<<findKthLargest(root,3)<<endl;
    cout<<"Kth Smallest [6] = "<<findKthSmallest(root,6)<<endl;

    return 0;
}

