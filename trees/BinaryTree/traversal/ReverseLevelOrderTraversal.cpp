#include <stack>
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

void ReverseLevelOrderTraversal(Node* root){
    stack<Node*> stk;
    queue<Node*> que;
    que.push(root);

    Node* curr=nullptr;
    while(!que.empty()){
        curr = que.front();
        que.pop();
        stk.push(curr);
        if (curr->right){
            que.push(curr->right);
        }
        if(curr->left){
            que.push(curr->left);
        }
    }

	cout<<"Tree[Reverse Level Order]:";
	while(stk.empty() == false){
	    curr=stk.top();stk.pop();
	    cout<<" "<<curr->data;
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

    ReverseLevelOrderTraversal(root);

    return 0;
}

