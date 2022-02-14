#include <iostream>
#include <unordered_set>

using namespace std;

typedef struct node {
    int key;
    node* next;
    node(int iKey){
        key = iKey;
        next = nullptr;
    }
}Node;

void PrintLinkedList(Node* node){
    while(node != nullptr) {
        cout<<node->key<<" ";
        node = node->next;
    }
    cout<<endl;
}

void findAndRemoveLoop(Node* node){
    unordered_set<Node*> hash;
    Node* prev = nullptr;
    while (node != nullptr) {
        if (hash.find(node) == hash.end()) {
            hash.insert(node);
            prev = node;
            node = node->next;
        } else {
            prev->next = nullptr; break;
        }
    }
}

int main(){
    Node* head = new Node(50);

    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    // add loop in the Linked List
    head->next->next->next->next->next = head->next->next;

    findAndRemoveLoop(head);

    cout<<"Linked List: ";
    PrintLinkedList(head);

    return 0;
}

