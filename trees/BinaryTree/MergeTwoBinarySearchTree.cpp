#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
}Node;

Node* createNode (int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void inOrder(Node *node){
    if (node != nullptr){
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
}

Node* merge(Node *root1, Node *root2){
    if(root1 == nullptr){
        return root2;
    }
    if(root2 == nullptr){
        return root1;
    }

    root1->data += root2->data;
    root1->left = merge(root1->left, root2->left);
    root1->right = merge(root1->right, root2->right);

    return root1;
}

int main(){
	Node* root1 = createNode(3);
	root1->left = createNode(1);
	root1->right = createNode(5);

	Node* root2 = createNode(4);
	root2->left = createNode(2);
	root2->right = createNode(6);

	Node* root = merge(root1, root2);
	inOrder(root);

	return 0;
}

