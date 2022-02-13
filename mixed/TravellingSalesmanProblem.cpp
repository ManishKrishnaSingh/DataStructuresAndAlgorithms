#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

#define N 4

int VISITEDALL = (1<<N) - 1; //1111

int tspUtil(int graph[N][N], int dp[][N], int mask, int curr, int start){
  if(mask == VISITEDALL){
    return graph[curr][start];
  }

  if(dp[mask][start] != -1){
     return dp[mask][start];
  }


  int minWeight = INT_MAX;

  for(int i=0; i<N; i++){
    if((mask & (1<<i)) == 0){
      int newWeight = graph[curr][i] + tspUtil(graph, dp, mask|(1<<i), i, start);

      minWeight = min(minWeight, newWeight);
    }

  }

  dp[mask][curr] = minWeight;

  return dp[mask][curr];
}

int tsp(int graph[N][N], int start){
    //int X = (1<<N);
    int X = pow(2,N);

    int dp[X][N];
    for(int i=0; i<X; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = -1;
        }
    }

    int mask = 1; // 0001

    return tspUtil(graph, dp, mask, start, start);
}

int main(){
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout<<"TSP = "<<tsp(graph, 0)<<endl;

    return 0;
}

