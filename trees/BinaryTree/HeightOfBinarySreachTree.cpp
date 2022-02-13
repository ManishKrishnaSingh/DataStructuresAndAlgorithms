#include <queue>
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

int height(Node* node){
    if(node != nullptr){
        int left  = height(node->left);
        int right = height(node->right);
        return 1 + (left>right?left:right);
    }
    return 0;
}

int findHeight(Node* root){
    int height = 0;
    queue<Node*> queue;

    queue.push(root);
    queue.push(nullptr);

    while(!queue.empty()){
        Node* front = queue.front(); queue.pop();
        if(front==nullptr){
            height++;
            if(!queue.empty()){
                queue.push(nullptr);
            }
        } else {
            if(front->left!=nullptr){
                queue.push(front->left);
            }
            if(front->right!=nullptr){
                queue.push(front->right);
            }
        }
    }
    return height;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(15);

    cout<<"Height [BST] = "<<height(root)<<endl;
    cout<<"Height [BST] = "<<findHeight(root)<<endl;

    return 0;
}

