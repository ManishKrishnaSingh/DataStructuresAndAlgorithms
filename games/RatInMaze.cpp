#include <bits/stdc++.h>

using namespace std;

#define N 4

typedef struct node {
	int x, y;
	int cost;
	int level;
	int mat[N][N];
	node * parent;
}Node;

Node* createNode(int mat[N][N], int x, int y, int level, Node* parent){
	Node * node = new Node();
	node->x = x;
	node->y = y;
	node->level = level;
	node->parent = parent;
	memcpy(node->mat, mat, sizeof(node->mat));
	return node;
}

class compare{
  public:
	bool operator()(Node* lft, Node* rht){
		return (lft->cost+lft->level) > (rht->cost+rht->level);
	}
};

int getCost(int x, int y, int nx, int ny){
	return sqrt(abs(nx-x)*abs(nx-x)+abs(ny-y)*abs(ny-y));
}

void printPath(Node* node){
	stack<pair<int, int>> stk;
	while(node != nullptr){
		stk.push({node->x, node->y});
		node = node->parent;
	}
	while(!stk.empty()){
		pair<int,int> p = stk.top();
		stk.pop();
		cout<<p.first<<" - "<<p.second<<endl;
	}
}

bool isSafe(int maze[N][N], int x, int y){
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}

void solveMaze(int maze[N][N], int x, int y){
	priority_queue<Node*, vector<Node*>, compare> pq;
	Node* node = createNode(maze, x, y, 0, nullptr);
	node->cost = getCost(x,y, x,y);

	pq.push(node);

	while(!pq.empty()){
		Node * top = pq.top();
		pq.pop();

		if(top->x==N-1 && top->y==N-1 && maze[top->x][top->y]==1){
			printPath(top);
			return;
		}

		if(isSafe(maze, top->x+1, top->y)){
			Node* child = createNode(maze, top->x+1, top->y, top->level+1, top);
			pq.push(child);
		}

		if(isSafe(maze, top->x, top->y+1)){
			Node* child = createNode(maze, top->x, top->y+1, top->level+1, top);
			pq.push(child);
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

