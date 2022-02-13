#include <bits/stdc++.h>

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

int findDistanceUtil(Node* root, int n1, int n2, int& distance){
    if (root == nullptr){
        return 0;
    }

    int left  = findDistanceUtil(root->left,  n1, n2, distance);
    int right = findDistanceUtil(root->right, n1, n2, distance);

    if (root->data == n1 || root->data == n2){
        if (left || right){
            distance = max(left, right);
            return 0;
        } else {
            return 1;
        }
    } else if (left && right){
        distance = left + right;
        return 0;
	} else if (left || right){
	    return 1 + max(left, right);
	}

	return 0;
}

int findDistance(Node* root, int n1, int n2){
    int distance = 0;
    findDistanceUtil(root, n1, n2, distance);
    return distance;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    cout<<"Distance[4,5] = "<<findDistance(root,4,5)<<endl;
    cout<<"Distance[2,9] = "<<findDistance(root,2,9)<<endl;

    return 0;
}
