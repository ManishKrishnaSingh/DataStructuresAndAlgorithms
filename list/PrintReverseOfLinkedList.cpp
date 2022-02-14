#include <iostream>

using namespace std;

typedef struct node {
	int data;
	node* next;
	node(int key){
		data = key;
		next = nullptr;
	}
}Node;

void PrintLinkedList(Node* node){
	Node* curr = node;
	while(curr != nullptr){
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl<<endl;
}

void ReverseRecursively(Node* node){
	if(node != nullptr){
	    ReverseRecursively(node->next);
	    cout<<node->data<<" ";
	}
}

void ReverseList(Node **nref) {
    Node *curr = (*nref);
    Node *prev = nullptr;
    Node *next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*nref) = prev;
}

int main(){
	Node* root = new Node(1);
	root->next = new Node(2);
	root->next->next = new Node(3);
	root->next->next->next = new Node(4);
	root->next->next->next = new Node(5);

	PrintLinkedList(root);
	ReverseRecursively(root);

	cout<<endl<<endl;

	ReverseList(&root);
	PrintLinkedList(root);

	return 0;
}

