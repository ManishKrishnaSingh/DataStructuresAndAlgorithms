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

Node* buildTreeUtil(int in[], int pre[], int low, int high, auto& m){
    if(low > high){
        return nullptr;
    }

    static int preIndex = 0;
    int curr = pre[preIndex++];
    Node* node = new Node(curr);
    if(low!=high){
        int iIndex = m[curr];
        node->left  = buildTreeUtil(in, pre, low, iIndex-1, m);
        node->right = buildTreeUtil(in, pre, iIndex+1, high, m);
    }
    return node;
}

Node* buildTree(int in[], int pre[], int n){
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[in[i]] = i;
    }
    return buildTreeUtil(in, pre, 0, n-1, m);
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
    int in[]  = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int pre[] = { 1, 2, 4, 8, 5, 3, 6, 7 };

    int n = sizeof(in)/sizeof(in[0]);
    Node* root = buildTree(in, pre, n);

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

