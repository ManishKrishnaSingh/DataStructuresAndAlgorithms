#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct node {
    int data;
    node *left, *right;
    node(int iKey){
        this->data = iKey;
        this->left = this->right = nullptr;
    }
}Node;

Node* buildTreeUtil(int in[], int post[], int low, int high, auto& m){
    if(low > high){
        return nullptr;
    }

    static int postIndex=high;
    int curr = post[postIndex--];
    Node* node = new Node(curr);
    if(low!=high) {
        int iIndex = m[curr];
        node->right = buildTreeUtil(in, post, iIndex+1, high, m);
        node->left  = buildTreeUtil(in, post, low, iIndex-1, m);
    }
    return node;
}

Node* buildTree(int in[], int post[], int n){
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[in[i]] = i;
    }
    return buildTreeUtil(in, post, 0, n-1, m);
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

int main(){
    int in[]   = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };

    int n = sizeof(in)/sizeof(in[0]);
    Node* root = buildTree(in, post, n);

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

