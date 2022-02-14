#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int key){
        this->data = key;
        this->next = nullptr;
    }
};

Node* addOne(Node* head){
	if (head != nullptr and head->next == nullptr) {
		head->data += 1;
		return head;
	}

	Node* temp = head;

	Node* pCrawl = head;
	while (pCrawl->next != nullptr) {
		if (pCrawl->data != 9) {
			temp = pCrawl;
		}
		pCrawl = pCrawl->next;
	}

	if (pCrawl->data == 9) {
		if (temp->data == 9) {
			Node* node = new Node(1);
			node->next = head;
			head = node;
			pCrawl = temp;
		} else {
			pCrawl = temp;
			pCrawl->data += 1;
			pCrawl = pCrawl->next;
		}

		while (pCrawl != nullptr) {
			pCrawl->data = 0;
			pCrawl = pCrawl->next;
		}
	} else {
		pCrawl->data += 1;
	}

	return head;
}

void PrintList(Node* node){
    while (node != nullptr) {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"nullptr"<<endl;
}

int main(void){
    Node* head = new Node(2);
    head->next = new Node(9);
    head->next->next = new Node(6);
    head->next->next->next = new Node(9);

    cout<<"List[I]:";
    PrintList(head);

    head = addOne(head);

    cout<<"List[F]:";
    PrintList(head);

    return 0;
}

