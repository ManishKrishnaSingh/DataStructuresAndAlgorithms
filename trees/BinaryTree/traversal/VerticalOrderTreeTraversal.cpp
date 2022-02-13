#include <map>
#include <vector>
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

void VerticalOrderUtil(Node* node, int hd, auto &map){
    if (node != nullptr){
        map[hd].push_back(node->data);
        VerticalOrderUtil(node->left, hd-1, map);
        VerticalOrderUtil(node->right, hd+1, map);
    }
}

void VerticalOrderTraversal(Node* root){
    map<int, vector<int>> map;
    VerticalOrderUtil(root,0,map);

    cout<<"Tree [VerticalOrder]:";
    for(auto iter : map){
        for(auto data : iter.second){
            cout<<" "<<data;
        }
        cout<<" #";
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

    VerticalOrderTraversal(root);

    return 0;
}

