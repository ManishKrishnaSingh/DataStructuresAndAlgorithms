#include <bits/stdc++.h>

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
    if(root != nullptr)
    {
        cout<<root->data<<" ";
        Print(root->left);
        Print(root->right);
    }
}

int MaxPathSum(Node* root, int& maxSum)
{
    if(root != nullptr)
    {
        int leftMaxSum  = max(0, MaxPathSum(root->left, maxSum));
        int rightMaxSum = max(0, MaxPathSum(root->right, maxSum));
        
        maxSum = max(maxSum, leftMaxSum + rightMaxSum + root->data);
        
        return max(leftMaxSum,rightMaxSum) + root->data;
    }
    return 0;
}

int MaxPathSum(Node* root)
{
    int maxSum = INT_MIN;

    MaxPathSum(root, maxSum);

    return maxSum;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout<<"BST : "; Print(root); cout<<endl;
    cout<<"Max Path SUM = "<<MaxPathSum(root);

    return 0;
}