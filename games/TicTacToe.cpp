#include <bits/stdc++.h>

using namespace std;

#define N 3

enum Player {ROBOT, HUMAN};

void showBoard(char board[N][N]){
    cout<<"[Board]:"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<" "<<board[i][j];
        }
        cout<<endl;
    }
}

bool IsRowCrossed(char board[N][N]){
    for (int i=0; i<N; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
            return true;
        }
    }
    return false;
}

bool IsColCrossed(char board[N][N]){
    for (int i=0; i<N; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-'){
            return true;
        }
    }
    return false;
}

bool IsDiagonalCrossed(char board[N][N]){
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'){
        return true;
    }
    return false;
}

bool IsSafe(char board[N][N]){
    return (!IsRowCrossed(board) and !IsColCrossed(board) and !IsDiagonalCrossed(board));
}

void TicTacToe(int player){
    char board[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            board[i][j] = '-';
        }
    }

    int moves[N*N];
    srand(time(NULL));
    for (int i=0; i<N*N; i++){
        moves[i] = i;
    }
    random_shuffle(moves, moves+N*N);

    int index=0, x, y;
    while (IsSafe(board) && index!=N*N){
        x = moves[index]/N;
        y = moves[index]%N;
        if (player == ROBOT){
            board[x][y] = 'O';
            cout<<"[ROBOT]: CELL["<<moves[index]+1<<"] => 'O'"<<endl;
        } else if (player == HUMAN){
            board[x][y] = 'X';
            cout<<"[HUMAN]: CELL["<<moves[index]+1<<"] => 'X'"<<endl;
        }
        index++;
        showBoard(board);
        player = (player==ROBOT)?HUMAN:ROBOT;
    }

    // print game result
    if (IsSafe(board) && index==N*N){
        cout<<"[Result] = DRWAN"<<endl;
    } else {
        if (player == ROBOT){
            cout<<"[Winner] = HUMAN"<<endl;
        } else if (player == HUMAN){
            cout<<"[Winner] = ROBOT"<<endl;
        }
    }
}

int main(){
    TicTacToe(HUMAN);

    return 0;
}
