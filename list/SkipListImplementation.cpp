#include <bits/stdc++.h>

using namespace std;

typedef struct node{
	int key;
	node **forward;

	node(int key, int level){
		this->key = key;
		forward = new node*[level+1];
		memset(forward, 0, sizeof(node*)*(level+1));
	}
}Node;

class SkipList{
	Node *head;
	int curLevel;
	int maxLevel;
public:
	SkipList(int maxLevel){
		this->curLevel = 0;
		this->maxLevel = maxLevel;
		this->head = new Node(-1, maxLevel);
	}

	int randomLevel(){
		return rand()%maxLevel;
	}

	void insert(int key){
	    Node *current = head;

	    Node *update[maxLevel];
	    memset(update, 0, sizeof(Node*)*(maxLevel));

	    for(int i=curLevel; i>=0; i--){
	        while(current->forward[i] != NULL && current->forward[i]->key < key){
	            current = current->forward[i];
	        }
	        update[i] = current;
	    }

	    current = current->forward[0];
	    if (current == NULL || current->key != key){
	        int rlevel = randomLevel();

	        if(rlevel > curLevel){
	            for(int i=curLevel+1; i<rlevel+1; i++){
	                update[i] = head;
	            }
	            curLevel = rlevel;
	        }

	        Node* node = new Node(key, rlevel);

	        // insert node by rearranging pointers
	        for(int i=0; i<=rlevel; i++){
	            node->forward[i] = update[i]->forward[i];
	            update[i]->forward[i] = node;
	        }
	        cout<<"["<<key<<"] inserted\n";
	    }
	}

	void erase(int key){
	    Node *current = head;

	    Node *update[maxLevel];
	    memset(update, 0, sizeof(Node*)*(maxLevel));

	    for(int i=curLevel; i>=0; i--){
	        while(current->forward[i] != NULL && current->forward[i]->key < key){
	            current = current->forward[i];
	        }
	        update[i] = current;
	    }

	    current = current->forward[0];
	    if(current != NULL and current->key == key){
	        for(int i=0; i<=curLevel; i++){
	            if(update[i]->forward[i] != current){
	                break;
	            }
	            update[i]->forward[i] = current->forward[i];
	        }
	        // Remove levels having no elements
	        while(curLevel > 0 && head->forward[curLevel] == 0){
	            curLevel--;
	        }
	        cout<<"["<<key<<"] deleted\n";
	    }
	}

	void search(int key){
	    Node *current = head;
	    for(int i=curLevel; i>= 0; i--){
	        while(current->forward[i] && current->forward[i]->key < key){
	            current = current->forward[i];
	        }
	    }

	    current = current->forward[0];
	    if(current and current->key == key){
	        cout<<"Found key: "<<key<<"\n";
	    }
	}

	void display(){
	    cout<<"\n***** Skip List *****"<<"\n";
	    for(int i=0; i<=curLevel; i++){
	        Node *node = head->forward[i];
	        cout<<"Level "<<i<<": ";
	        while(node != NULL){
	            cout<<node->key<<" ";
	            node = node->forward[i];
	        }
	        cout<<"\n";
	    }
	}
};

int main(){
	//random num generator
	srand((unsigned)time(0));

	SkipList skipList(4);

	skipList.insert(40);
	skipList.insert(11);
	skipList.insert(12);
	skipList.insert(15);
	skipList.insert(19);
	skipList.insert(17);
	skipList.insert(26);
	skipList.insert(21);
	skipList.insert(25);
	skipList.insert(32);
	skipList.insert(35);
	skipList.insert(27);
	skipList.insert(48);
	skipList.insert(50);
	skipList.insert(50);
	skipList.display();

	skipList.erase(19);
	skipList.display();

	skipList.search(25);

	return 0;
}

