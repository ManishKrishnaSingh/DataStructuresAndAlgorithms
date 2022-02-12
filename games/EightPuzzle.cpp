#include <queue>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

#define N 3

typedef struct node{
    int x, y;
    int cost;
    int level;
    int mat[N][N];
    node * parent;
}Node;

Node* createNode(int mat[N][N], int x, int y, int nx, int ny, int level, Node* parent){
    Node* node = new Node();

    memcpy(node->mat, mat, sizeof(node->mat));
    swap(node->mat[x][y], node->mat[nx][ny]);

    node->level = level;
    node->parent = parent;

    node->cost = INT_MAX;
    node->x = nx;
    node->y = ny;

    return node;
}

int calculateCost(int mat[N][N], int final[N][N]){
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mat[i][j] != final[i][j]){
                count++;
            }
        }
    }
    return count;
}

class compare{
    public:
    bool operator()(const Node* lft, const Node* rht){
        return (lft->cost+lft->level) > (rht->cost+rht->level);
    }
};

bool isSafe(int x, int y){
    if(x>=0 && x<N && y>=0 && y<N){
        return true;
    }
    return false;
}

void PrintSolution(Node* node){
    if(node!=nullptr){
        PrintSolution(node->parent);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<node->mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-------------"<<endl;
    }
}

void solveEightPuzzle(int initial[N][N], int x, int y, int final[N][N]){
    priority_queue<Node*, vector<Node*>, compare> pq;

    Node* root = createNode(initial, x, y, x, y, 0, nullptr);
    root->cost = calculateCost(root->mat, final);

    pq.push(root);
    while(!pq.empty()){
        Node* T = pq.top();
        pq.pop();

        if(T->cost == 0){
            cout<<"Walla....."<<endl;
            PrintSolution(T); return;
        }

        if(isSafe(T->x+1, T->y)){
            Node* node = createNode(T->mat, T->x, T->y, T->x+1, T->y, T->level+1, T);
            node->cost = calculateCost(node->mat, final);
            pq.push(node);
        }
        if(isSafe(T->x-1, T->y)){
            Node* node = createNode(T->mat, T->x, T->y, T->x-1, T->y, T->level+1, T);
            node->cost = calculateCost(node->mat, final);
            pq.push(node);
        }
        if(isSafe(T->x, T->y+1)){
            Node* node = createNode(T->mat, T->x, T->y, T->x, T->y+1, T->level+1, T);
            node->cost = calculateCost(node->mat, final);
            pq.push(node);
        }
        if(isSafe(T->x, T->y-1)){
            Node* node = createNode(T->mat, T->x, T->y, T->x, T->y-1, T->level+1, T);
            node->cost = calculateCost(node->mat, final);
            pq.push(node);
        }
    }
}

int main(){
    int initial[N][N]={
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int final[N][N]={
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    int x = 1, y = 2;
    solveEightPuzzle(initial, x, y, final);

    return 0;
}

