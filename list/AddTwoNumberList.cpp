#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int data;
    node* next;
    node(int key){
        this->data = key;
        this->next = nullptr;
    }
}Node;

Node* addTwoNumList(Node* head1, Node* head2){
    stack<int> s1,s2;

    while(head1!=nullptr){
        s1.push(head1->data);
        head1 = head1->next;
    }
    while(head2!=nullptr){
        s2.push(head2->data);
        head2 = head2->next;
    }

    Node* head = nullptr;
    int x, y, sum, carry = 0;
    while(!s1.empty() or !s2.empty()){
        x=0; y=0;
        if(!s1.empty()){
            x=s1.top(); s1.pop();
        }
        if(!s2.empty()){
            y=s2.top(); s2.pop();
        }

        sum = x+y+carry;
        carry = sum / 10;

        Node* node=new Node(sum%10);
        if(head == nullptr){
            head=node;
        } else {
            node->next=head; head=node;
        }
    }

    if(carry > 0){
        Node* node = new Node(carry);
        node->next=head; head=node;
    }

    return head;
}

void PrintList(Node *node){
    cout<<"Linked List:";
    while(node != nullptr){
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}

int main(){
    Node *head1 = new Node(5);
    head1->next = new Node(6);
    head1->next->next = new Node(6);

    Node *head2 = new Node(1);
    head2->next = new Node(8);

    Node* head=addTwoNumList(head1,head2);
    PrintList(head); // print result list

    return 0;
}

