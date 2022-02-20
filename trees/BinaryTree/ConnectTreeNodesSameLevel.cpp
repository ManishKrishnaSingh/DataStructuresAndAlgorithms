#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
    node *nextRight;
    node(int key){
        this->data = key;
        this->left = this->right = this->nextRight = nullptr;
    }
}Node;

void connectNodesAtSameLevel(Node* root){
    queue<Node*> queue;

    queue.push(root);
    queue.push(nullptr);

    while(!queue.empty()) {
        Node *node = queue.front(); queue.pop();
        if(node != nullptr) {
            node->nextRight = queue.front();
            if(node->left){
                queue.push(node->left);
            }
            if(node->right){
                queue.push(node->right);
            }
        } else if(!queue.empty()){
            queue.push(NULL);
        }
    }
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(10);

    connectNodesAtSameLevel(root);
    
    cout<<"nextRight pointers are"<<endl;
    cout<<"--> nextRight of "<<root->data<<" is "<<(root->nextRight?root->nextRight->data:-1)<<endl;
    cout<<"--> nextRight of "<<root->left->data<<" is "<<(root->left->nextRight ? root->left->nextRight->data:-1)<<endl;

    return 0;
}

