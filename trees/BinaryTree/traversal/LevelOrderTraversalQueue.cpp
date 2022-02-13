#include <queue>
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

void LevelOrderTraversal(Node* root){
    cout<<"Tree[Level Order]: ";
    if(root != nullptr){
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            Node* node = queue.front();
            queue.pop();
            cout<<node->data<<" ";
            if(node->left!=nullptr){
                queue.push(node->left);
            }
            if(node->right!=nullptr){
                queue.push(node->right);
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

    LevelOrderTraversal(root);

    return 0;
}

