#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int data;
    node *prev, *next;
    node(int key){
        this->data = key;
        this->prev=this->next=nullptr;
    }
}Node;

Node *partition(Node *left, Node *right){
    Node *pivot = right;
    Node *iter = left->prev;
    for(Node *curr=left; curr!=right; curr=curr->next){
        if(curr->data <= pivot->data){
            if(iter==nullptr){
                iter = left;
            } else {
                iter = iter->next;
            }
            swap(iter->data, curr->data);
        }
    }

    if(iter==nullptr){
        iter = left;
    } else {
        iter = iter->next;
    }
    swap(iter->data, pivot->data);

    return iter;
}

void QuickSort(Node *left, Node *right){
    if(right!=nullptr && left!=right && left!=right->next){
        Node *pivot = partition(left, right);
        QuickSort(left, pivot->prev);
        QuickSort(pivot->next, right);
    }
}

void PrintLinkedList(Node *head){
    Node* curr = head;
    while(curr != NULL){
        cout<<" "<<curr->data;
        curr = curr->next;
    }
}

int main(){
    Node *head = new Node(4);
    Node *node1 = new Node(8);
    node1->prev=head; head->next=node1;
    Node *node2 = new Node(7);
    node2->prev=node1; node1->next=node2;
    Node *node3 = new Node(5);
    node3->prev=node2; node2->next=node3;
    Node *node4 = new Node(12);
    node4->prev=node3; node3->next=node4;

    //2-8-3-5-10-nullptr
    QuickSort(head,node4);
    PrintLinkedList(head);

    return 0;
}

