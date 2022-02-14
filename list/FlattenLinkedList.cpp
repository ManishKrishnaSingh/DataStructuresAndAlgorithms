#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *right, *down;
    node(int iKey){
        this->data = iKey;
        this->right = this->down = nullptr;
    }
}Node;

Node* merge(Node* a, Node* b){
    if(a==nullptr){
        return b;
    }
    if(b==nullptr){
        return a;
    }

    Node* node;
    if (a->data < b->data){
        node = a;
        node->down = merge(a->down, b);
    } else {
        node = b;
        node->down = merge(a, b->down);
    }
    node->right = nullptr;

    return node;
}

Node* flatten(Node* root){
    if(root==nullptr || root->right==nullptr){
        return root;
    }
    //recur for list on right & merge
    root->right = flatten(root->right);
    root = merge(root, root->right);
    return root;
}

Node* push(Node* head, int data){
    Node* node = new Node(data);
    node->down = head;
    return head=node;
}

void PrintLinkedList(Node* head){
    Node* curr = head;
    cout<<"Linked List:";
    while(curr!=nullptr){
        cout<<" "<<curr->data;
        curr = curr->down;
    }
}

int main(){
	Node* head=nullptr;

	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->right = push(head->right, 20);
	head->right = push(head->right, 10);

	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);

	head->right->right->right = push(head->right->right->right, 45);
	head->right->right->right = push(head->right->right->right, 40);
	head->right->right->right = push(head->right->right->right, 35);
	head->right->right->right = push(head->right->right->right, 20);

	head = flatten(head);
	PrintLinkedList(head);

	return 0;
}

