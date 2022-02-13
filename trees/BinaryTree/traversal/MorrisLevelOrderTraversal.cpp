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

void LevelOrderTraversal(Node *root){
    map<int, vector<int>> map;

    int level = 0;
    Node* curr = root;
    while (curr != nullptr){
        if (curr->left == nullptr){
            map[level].push_back(curr->data);

            curr = curr->right;
            if(curr!=nullptr){
                level++;
            } else {
                level--;
            }
        } else {
            int count = 0;

            Node* prev = curr->left; //in order predecessor
            while(prev->right!=nullptr and prev->right!=curr){
                prev = prev->right;
                count++;
            }

            if (prev->right == nullptr) {
                map[level].push_back(curr->data);
                prev->right = curr;
                curr = curr->left;
                level++;
            } else {
                prev->right = nullptr;
                curr = curr->right;
                level -= ++count;
            }
        }
    }

    cout<<"Tree[Level Order]:";
    for(auto item : map){
        for(auto data: item.second){
            cout<<" "<<data;
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

