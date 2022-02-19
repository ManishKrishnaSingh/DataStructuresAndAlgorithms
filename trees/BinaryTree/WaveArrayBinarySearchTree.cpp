#include <stack>
#include <vector>
#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
    node(int key){
        data = key;
        left = right = nullptr;
    }
}Node;

void createWaveArray(Node* root){
    vector<int> wave;

    stack<Node*> stk;
    Node* curr = root;
    while (curr!=nullptr || !stk.empty()) {
        while (curr!=nullptr) {
            stk.push(curr);
            curr=curr->left;
        }
        curr=stk.top(); stk.pop();

        // insert into wave array
        wave.push_back(curr->data);

        curr = curr->right;
    }

    //convert sorted array into wave
    for(int i=0; i+1<wave.size(); i+=2){
        swap(wave[i], wave[i+1]);
    }

    //print the final wave array
    cout<<"Wave Array:";
    for(int i=0; i<wave.size(); i++){
        cout<<" "<<wave[i];
    }
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(15);

    createWaveArray(root);

    return 0;
}

