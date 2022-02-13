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

vector<int> findIntermediate(Node* root, int n1, int n2){
    vector<int> result;
    if (root != nullptr){
        if(root->left !=nullptr){
            result = findIntermediate(root->left, n1, n2);
        }

        if (n1 <= root->data && root->data <= n2) {
            result.push_back(root->data);
        }

        if(root->right !=nullptr){
            auto rhtNodes=findIntermediate(root->right, n1, n2);
            result.insert(result.end(), rhtNodes.begin(), rhtNodes.end());
        }
    }
    return result;
}

int findMedian(Node* root, int n1, int n2){
    auto V = findIntermediate(root, n1, n2);

    int N = V.size();
    if(N%2 == 1){
        return V[N/2];
    } else {
         return (V[(N-1)/2] + V[N/2]) / 2;
    }
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(15);
    root->left->right->left = new Node(4);

    cout<<"MEDIAN [3,11] = "<<findMedian(root, 3, 11);

    return 0;
}

