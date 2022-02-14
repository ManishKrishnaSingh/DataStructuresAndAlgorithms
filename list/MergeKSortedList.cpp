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

Node* mergeSorted(Node* x, Node* y){
    if(x==nullptr){
        return y;
    }
    if(y==nullptr){
        return x;
    }

    Node* node=nullptr;
    if(x->data <= y->data){
        node = x;
        node->next = mergeSorted(x->next, y);
    } else {
        node = y;
        node->next = mergeSorted(x, y->next);
    }
    return node;
}

Node* mergeSortedLists(Node* arr[], int K){
    Node* head = arr[0];
	cout<<"Linked List: ";
    for(int i=1; i<K; i++){
        head = mergeSorted(head, arr[i]);
    }
    return head;
}

void printLinkedList(Node* node){
    while(node != nullptr){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main(){
    int K = 3;
    int N = 4;

    Node* arr[K];

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(4);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    Node* head = mergeSortedLists(arr, K);

    printLinkedList(head);

    return 0;
}

