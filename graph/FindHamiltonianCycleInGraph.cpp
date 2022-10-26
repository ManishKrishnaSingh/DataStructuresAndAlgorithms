#include <bits/stdc++.h>

using namespace std;

#define V 5

bool isSafe(int v, bool graph[V][V], int path[], int pos){
    if(graph[path[pos-1]][v] == 0){
        return false;
    }

    for(int i=0; i<pos; i++){
        if(path[i] == v){
            return false;
        }
    }

    return true;
}

bool hamiltonianCycle(bool graph[V][V], int path[], int pos){
    if(pos == V){
        if(graph[path[pos-1]][path[0]] == 1){
            return true;
        } else {
            return false;
        }
    }

    for(int v=1; v<V; v++){
        if(isSafe(v, graph, path, pos)){
            path[pos] = v;

            if(hamiltonianCycle(graph, path, pos+1)){
                return true;
            }

            path[pos] = -1;
        }
    }
    return false;
}

void findHamiltonianPath(bool graph[V][V]){
    int path[V];
    for(int i=0; i<V; i++)
    {
        path[i] = -1;
    }

    path[0] = 0;
    if(hamiltonianCycle(graph,path,1)){
        cout<<"Solution: ";
        for(int i=0; i<V; i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<path[0]<<endl;
    } else {
        cout<<"No Solution Exists!";
    }
}

int main(){
    bool graph[V][V]={
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    findHamiltonianPath(graph);

    return 0;
}