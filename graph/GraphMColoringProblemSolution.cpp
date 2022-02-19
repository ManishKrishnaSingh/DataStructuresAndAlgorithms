#include <iostream>

using namespace std;

#define V 4

bool isSafe(bool graph[V][V], int assigned[V], int v, int colour){
    for(int i=0; i<v; i++){
        if(graph[v][i] && assigned[i]==colour){
            return false;
        }
    }
    return true;
}

bool IsPossible(bool graph[V][V], int mColour, int assigned[V], int v){
    if(v == V){
        return true;
    }
    for(int color=1; color<=mColour; color++){
        if(isSafe(graph, assigned, v, color)){
            assigned[v] = color;
            if(IsPossible(graph, mColour, assigned, v+1)){
                return true;
            }
            assigned[v] = -1;
        }
    }
    return false;
}

void applyColour(bool graph[V][V], int mColour){
    int assigned[V];
    for(int i=0; i<V; i++){
        assigned[i] = -1;
    }

    if(!IsPossible(graph, mColour, assigned, 0)){
         cout<<"No Solution!"<<endl;
    } else {
        //Print Solution
        for(int v=0; v<V; v++){
            cout<<v<<" ==> "<<assigned[v]<<endl;
        }
    }
}

int main(){
    bool graph[V][V]={
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    int mColour=3;//no of colors

    applyColour(graph, mColour);

    return 0;
}

