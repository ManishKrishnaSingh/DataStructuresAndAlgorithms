#include <bits/stdc++.h>

using namespace std;

#define N 4

int getCost(int x, int y){
	return sqrt(abs(N-1-x)*abs(N-1-x)+abs(N-1-y)*abs(N-1-y));
}

typedef struct node {
	int x, y;
	int cost;
	int level;
	node * parent;
}Node;

Node* createNode(int x, int y, int level, Node* parent){
	Node * node = new Node();
	node->x = x;
	node->y = y;
	node->cost = getCost(x, y);
	node->level = level;
	node->parent = parent;
	return node;
}

class compare{
  public:
	bool operator()(Node* lft, Node* rht){
		return (lft->cost+lft->level) > (rht->cost+rht->level);
	}
};

void PrintPath(Node* node){
	stack<pair<int, int>> stk;
	while(node != nullptr){
		stk.push({node->x, node->y});
		node = node->parent;
	}
	while(!stk.empty()){
		auto top = stk.top(); stk.pop();
		cout<<top.first<<" - "<<top.second<<endl;
	}
}

bool isSafe(int maze[N][N], int x, int y){
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}

void solveMaze(int maze[N][N], int x, int y){
	priority_queue<Node*, vector<Node*>, compare> pq;

	pq.push(createNode(x, y, 0, nullptr));

	while(!pq.empty()){
		Node* top = pq.top(); pq.pop();

		if(top->x==N-1 && top->y==N-1 && maze[top->x][top->y]==1){
			PrintPath(top); return;
		}

		if(isSafe(maze, top->x+1, top->y)){
			pq.push(createNode(top->x+1, top->y, top->level+1, top));
		}

		if(isSafe(maze, top->x, top->y+1)){
			pq.push(createNode(top->x, top->y+1, top->level+1, top));
		}
	}
}

int main(){
    int maze[N][N] = {
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 0 },
        { 1, 1, 1, 1 }
    };

    solveMaze(maze, 0, 0);

    return 0;
}