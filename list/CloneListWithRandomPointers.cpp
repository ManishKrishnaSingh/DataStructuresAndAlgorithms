#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct node {
    int data;
    node *next, *random;

    node(int data){
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
}Node;

class LinkedList {
  public:
    Node *head;

    LinkedList(){
        this->head = nullptr;
    }

    void push(int data){
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }

    void display(){
        Node *pCrawl = head;
        while (pCrawl != nullptr){
            Node *random = pCrawl->random;

            int ndata = pCrawl->data;
            int rdata = (random != nullptr) ? random->data : -1;
            cout<<"Node => ND:"<<ndata<< "; "<<"RD:"<<rdata<<endl;

			pCrawl = pCrawl->next;
		}
		cout << endl;
	}

	LinkedList* clone(){
	    LinkedList *clone = new LinkedList();

	    Node *pCrawl = head;
	    Node *pClone = nullptr;

	    unordered_map<Node*, Node*> m;
		while (pCrawl != nullptr){
		    pClone = new Node(pCrawl->data);
		    m[pCrawl] = pClone;
		    pCrawl = pCrawl->next;
		}

		pCrawl = head;
		while (pCrawl != nullptr){
			pClone = m[pCrawl];
			pClone->next = m[pCrawl->next];
			pClone->random = m[pCrawl->random];
			pCrawl = pCrawl->next;
		}

		clone->head = m[head];

		return clone;
	}
};

int main(){
    LinkedList *rpList = new LinkedList();

    rpList->push(55);
    rpList->push(12);
    rpList->push(45);
    rpList->push(72);
    rpList->push(51);

    // set random pointers
    rpList->head->random = rpList->head->next->next;
    rpList->head->next->random = rpList->head->next->next->next;
    rpList->head->next->next->next->next->random = rpList->head->next;

    cout << "List[O]\n";
    rpList->display();

    cout << "List[C]\n";
    LinkedList *clone = rpList->clone();
    clone->display();

    return 0;
}

