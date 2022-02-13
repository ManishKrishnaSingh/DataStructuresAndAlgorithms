#include <bits/stdc++.h>

using namespace std;

#define N 8

void PrintBoard(int board[N][N]){
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool IsSafe(int board[N][N], int row, int col){
    int i, j;
    // left colums
    for(int i=0; i<col; i++){
        if(board[row][i]==1){
            return false;
        }
    }
    // upper diagonal on left side
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    // lower diagonal on left side
    for(i=row, j=col; i<N && j>=0; i++, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

bool solveNQueen(int board[N][N], int col){
    if(col >= N){
        return true;
    }
    for(int row=0; row<N; row++){
        if(IsSafe(board, row, col)){
            board[row][col] = 1;
            if(solveNQueen(board, col+1)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int board[N][N] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    if(solveNQueen(board, 0)){
        PrintBoard(board);
    } else {
        cout<<"No solution!"<<endl;
    }
    return 0;
}

