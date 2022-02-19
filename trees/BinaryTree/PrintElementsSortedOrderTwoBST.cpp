#include <stack>
#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
}Node;

Node* createNode (int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void inOrder(Node *node){
    if (node != nullptr){
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
}

void merge(Node *root1, Node *root2){
    if (root1 == nullptr){
        inOrder(root2); return;
    }
    if (root2 == nullptr){
        inOrder(root1); return ;
    }

    stack<Node*> s1;
    stack<Node*> s2;

    // Current nodes BST's
    Node *curr1 = root1;
    Node *curr2 = root2;

    while (curr1 != nullptr || !s1.empty() || curr2 != nullptr || !s2.empty()){
        if (curr1 != nullptr || curr2 != nullptr){
            if (curr1 != nullptr){
                s1.push(curr1);
                curr1 = curr1->left;
            }
            if (curr2 != nullptr){
                s2.push(curr2);
                curr2 = curr2->left;
            }
        } else {
            if (s1.empty()){
                while (!s2.empty()){
                    curr2 = s2.top();s2.pop();
                    curr2->left = nullptr;
                    inOrder(curr2);
                }
                return;
            }
            if (s2.empty()){
                while (!s1.empty()){
                    curr1 = s1.top(); s1.pop();
                    curr1->left = nullptr;
                    inOrder(curr1);
                }
                return;
            }

            // Pop elements
            curr1 = s1.top(); s1.pop();
            curr2 = s2.top(); s2.pop();

            if (curr1->data < curr2->data){
                cout<<curr1->data<<" ";
                curr1 = curr1->right;
                s2.push(curr2);
                curr2 = nullptr;
            } else {
                cout<<curr2->data<<" ";
                curr2 = curr2->right;
                s1.push(curr1);
                curr1 = nullptr;
			}
		}
	}
}

int main(){
	Node* root1 = createNode(3);
	root1->left = createNode(1);
	root1->right = createNode(5);

	Node* root2 = createNode(4);
	root2->left = createNode(2);
	root2->right = createNode(6);

	merge(root1, root2);

	return 0;
}

