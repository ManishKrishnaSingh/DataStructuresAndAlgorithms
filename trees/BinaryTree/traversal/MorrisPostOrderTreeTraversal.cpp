#include <stack>
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

void MorrisPostOrderTraversal(Node* root){
    stack<int> stk;
    cout<<"Tree [PostOrder]:";
    if (root != nullptr){
        Node* succ;
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->right == nullptr) {
                stk.push(curr->data);
                curr = curr->left;
            } else {
                succ = curr->right; //in order successor
                while (succ->left != nullptr && succ->left != curr){
                    succ = succ->left;
                }

                if (succ->left == nullptr) {
                    stk.push(curr->data);
                    succ->left = curr;
                    curr = curr->right;
                } else {
                    succ->left = nullptr;
                    curr = curr->left;
                }
            }
        }
    }

    while(!stk.empty()){
        cout<<" "<<stk.top(); stk.pop();
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

    MorrisPostOrderTraversal(root);

    return 0;
}

