#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    node* left;
    node* right;
    node(int key){
        data = key;
        left = right = nullptr;
    }
}Node;

void Print(Node* root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<" ";
        Print(root->left);
        Print(root->right);
    }
}

Node* DeleteLeaf(Node* root)
{
    if(root!=nullptr)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        root->left  = DeleteLeaf(root->left);
        root->right = DeleteLeaf(root->right);
    }
    return root;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9); 

    cout<<"BST:"; Print(root); cout<<endl;
    DeleteLeaf(root); //Delete Leaf Nodes
    cout<<"BST:"; Print(root); cout<<endl;

    return 0;
}
