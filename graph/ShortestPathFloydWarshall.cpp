#include <climits>
#include <iostream>

using namespace std;

#define V   4
#define INF INT_MAX

void floydWarshall(int graph[V][V]){
    int distance[V][V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            distance[i][j] = graph[i][j];
        }
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                if(distance[i][k]!=INF && distance[k][j]!=INF && distance[i][j] > distance[i][k]+distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    cout<<"Solution: "<<endl;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(distance[i][j]==INF){
                cout<<"INF ";
            } else {
                cout<<distance[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int graph[V][V] = {
        {   0,  5,  INF,  10 },
        { INF,  0,    3, INF },
        { INF, INF,   0,   1 },
        { INF, INF, INF,   0 }
    };

    floydWarshall(graph);

    return 0;
}

