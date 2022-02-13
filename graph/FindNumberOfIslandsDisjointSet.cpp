#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define M 5
#define N 5

bool isSafe(int mat[M][N], int i, int j){
    return (i<N && i>=0 && j<N && j>=0 && mat[i][j]==1);
}

class DisjointUnionSets {
    vector<int> rank;
    vector<int> parent;
  public:
    DisjointUnionSets(int n){
        rank.resize(n);
        parent.resize(n);
        // init parent list
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if (parent[x] != x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot){
            return;
        }

        if (rank[xRoot] < rank[yRoot]){
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]){
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot] = rank[xRoot]+1;
        }
    }
};

int findCountOfIslands(int mat[M][N]){
    DisjointUnionSets *dus = new DisjointUnionSets(M*N);

    for(int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (mat[i][j] == 0){
                continue;
            }

            if(isSafe(mat, i+1, j)){
                dus->Union(i*N+j, (i+1)*(N)+(j));
            }
            if(isSafe(mat, i-1, j)){
                dus->Union(i*N+j, (i-1)*(N)+(j));
            }
            if(isSafe(mat, i, j+1)){
                dus->Union(i*N+j, (i)*(N)+(j+1));
            }
            if(isSafe(mat, i, j-1)){
                dus->Union(i*N+j, (i)*(N)+(j-1));
            }
            if(isSafe(mat, i+1, j+1)){
                dus->Union(i*N+j, (i+1)*(N)+(j+1));
            }
            if(isSafe(mat, i+1, j-1)){
                dus->Union(i*N+j, (i+1)*(N)+(j-1));
            }
            if(isSafe(mat, i-1, j+1)){
                dus->Union(i*N+j, (i-1)*N+(j+1));
            }
            if(isSafe(mat, i-1, j-1)){
                dus->Union(i*N+j, (i-1)*N+(j-1));
            }
        }
    }

    //array each set frequency
    int *frequency = new int[M*N];
    int numberOfIslands = 0;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (mat[i][j] == 1){
                int x = dus->find(i*N+j);
                // If frequency of set is 0,
                // increment numberOfIslands
                if (frequency[x] == 0){
                    numberOfIslands++;
                }
                frequency[x]++;
            }
        }
    }
    return numberOfIslands;
}

int main(){
    int mat[M][N] = {
        { 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 1 }
    };

    int nOfIslands = findCountOfIslands(mat);
    cout<<"Number of Islands = "<<nOfIslands<<endl;

    return 0;
}

