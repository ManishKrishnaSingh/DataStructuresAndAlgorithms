#include <iostream>

using namespace std;

const int N = 4;

void printMatrix(int mat[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotateLeft(int mat[N][N]){
    //reverse rows
    int low,high;
    for(int i=0; i<N; i++){
        low=0; high=N-1;
        while(low<high){
            swap(mat[i][low], mat[i][high]);
            low++, high--;
        }
    }

    //transpose matrix
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}

void rotateRight(int mat[N][N]){
    //reverse cols
    int low,high;
    for(int i=0; i<N; i++){
        low=0; high=N-1;
        while(low<high){
            swap(mat[low][i], mat[high][i]);
            low++, high--;
        }
    }

    //transpose matrix
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}

int main(){
    int mat[N][N] ={
        {1,  2,   3,  4},
        {5,  6,   7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    printMatrix(mat);

    rotateLeft(mat);
    printMatrix(mat);

    rotateRight(mat);
    printMatrix(mat);

    return 0;
}

