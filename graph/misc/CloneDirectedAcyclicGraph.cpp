#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int value;
    vector<node*> neighbours;
}Node;

Node *buildGraph(){
    Node *node1 = new Node();
    node1->value = 1;

    Node *node2 = new Node();
    node2->value = 2;

    Node *node3 = new Node();
    node3->value = 3;

    Node *node4 = new Node();
    node4->value = 4;

    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;

    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;

    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;

    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;

    return node1;
}

void bfs(Node *src){
    queue<Node*> gQueue;
    map<Node*, bool> visited;

    gQueue.push(src);
    visited[src] = true;

    while (!gQueue.empty()){
        Node *u = gQueue.front();
        gQueue.pop();

        cout<<"Node [V="<<u->value<<"; A:"<<u<<"]\n";

        vector<Node*> v = u->neighbours;
        for (int i = 0; i < v.size(); i++){
            if (!visited[v[i]]){
                visited[v[i]] = true;
                gQueue.push(v[i]);
            }
        }
    }
    cout << endl;
}

Node *cloneGraph(Node *src){
    queue<Node*> q;
    map<Node*, Node*> m;

    q.push(src);
    Node *node;

    node = new Node();
    node->value = src->value;

    m[src] = node;
    while (!q.empty()){
        Node *u = q.front();
        q.pop();
        vector<Node *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++){
            if (m[v[i]] == NULL){
                node = new Node();
                node->value = v[i]->value;
                m[v[i]] = node;
                q.push(v[i]);
            }
            m[u]->neighbours.push_back(m[v[i]]);
        }
    }
    return m[src];
}

int main(){
    Node *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);

    Node *newsrc = cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);

    return 0;
}

