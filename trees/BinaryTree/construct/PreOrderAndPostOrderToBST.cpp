#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left, *right;
    node(int iKey){
        this->data = iKey;
        this->left = this->right = nullptr;
    }
}Node;

Node* buildTreeUtil(int pre[], int post[], int low, int high, int n){
    if(low>high){
        return nullptr;
    }

    static int preIndex=0;
    int curr = pre[preIndex++];
    Node* root = new Node (curr);
    if(low!=high){
        int idx;//next item of pre[] in post[]
        for(idx=low; idx<=high; ++idx){
            if (pre[preIndex] == post[idx]){
                break;
            }
        }
        if(idx<=high){
            root->left  = buildTreeUtil(pre, post, low, idx, n);
            root->right = buildTreeUtil(pre, post, idx+1, high-1, n);
        }
    }
    return root;
}

Node *buildTree(int pre[], int post[], int n){
    return buildTreeUtil(pre, post, 0, n-1, n);
}

void PreOrderTraversal(Node* node){
    if(node != nullptr){
        cout<<" "<<node->data;
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
}
void InOrderTraversal(Node* node){
    if(node != nullptr){
        InOrderTraversal(node->left);
        cout<<" "<<node->data;
        InOrderTraversal(node->right);
    }
}
void PostOrderTraversal(Node* node){
    if(node != nullptr){
        PostOrderTraversal(node->left);
        PostOrderTraversal(node->right);
        cout<<" "<<node->data;
    }
}

int main (){
    int pre[]  = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};

    int n = sizeof(pre)/sizeof(pre[0]);
    Node *root = buildTree(pre, post, n);

    cout<<"Tree [PreOrder]  => ";
    PreOrderTraversal(root);
    cout<<endl;
    cout<<"Tree [InOrder]   => ";
    InOrderTraversal(root);
    cout<<endl;
    cout<<"Tree [PostOrder] => ";
    PostOrderTraversal(root);

    return 0;
}

