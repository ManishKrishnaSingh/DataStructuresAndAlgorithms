#include <bits/stdc++.h>

using namespace std;

#define N 4

typedef struct node{
	node* parent;
	int jobId;
	int workerId;
	int pathCost;
	int totalCost;
	bool assigned[N];
}Node;

Node* createNode(int workerId, int jobId, bool assigned[N], Node* parent){
	Node* node = new Node();

	node->jobId = jobId;
	node->workerId = workerId;
	node->parent = parent;

	for(int i=0; i<N; i++){
		node->assigned[i] = assigned[i];
	}

	node->assigned[jobId] = true;

	return node;
}


int calculateCost(int costMatrix[N][N], int worker, int job, bool assigned[N]){
	bool available[N];
	for(int i=0; i<N; i++){
		available[i] = !assigned[i];
	}

	int cost = 0;
	for(int w=worker+1; w<N; w++){
		int idx = -1;
		int min = INT_MAX;
		for(int j=0; j<N; j++){
			if(!assigned[j] && available[j] && min > costMatrix[w][j]){
				min = costMatrix[w][j];
				idx = j;
			}
		}
		cost += min;
		available[idx] = false;
	}
	return cost;
}

class compare{
    public:
	bool operator()(const Node* lft, const Node* rht)const {
		return lft->totalCost > rht->totalCost;
	}
};

void printSolution(Node* node){
    if(node != NULL && node->workerId >= 0){
        printSolution(node->parent);
        cout<<node->workerId<<" - "<<node->jobId<<" = "<<node->totalCost<<endl;
    }
}

int minimumCost(int costMatrix[N][N]){
	bool assigned[N];
	for(int i=0; i<N; i++){
		assigned[i] = false;
	}

	priority_queue<Node*, vector<Node*>, compare> pq;

	Node* root = createNode(-1, -1, assigned, NULL);
	root->pathCost = root->totalCost = 0;

	pq.push(root);
	while(!pq.empty()){
	    Node* T = pq.top();
	    pq.pop();

	    int w = T->workerId + 1;
	    if(w == N){
	        //printSolution(T);
	        return T->totalCost;
	    }

	    for(int j=0; j<N; j++){
	        if(!T->assigned[j]){
	            Node* node = createNode(w, j, T->assigned, T);
	            node->pathCost = T->pathCost + costMatrix[w][j];
	            node->totalCost = node->pathCost + calculateCost(costMatrix, w, j, node->assigned);

	            pq.push(node);
	        }
	    }
	}

	return INT_MAX;
}

int main(){
    // x-axix - Worker
    // y-axix - Job to be assigned
    int costMatrix[N][N] ={
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    cout<<"Minimum Cost = "<<minimumCost(costMatrix)<<endl;

    return 0;
}

