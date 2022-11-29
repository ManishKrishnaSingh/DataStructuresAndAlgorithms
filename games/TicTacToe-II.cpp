#include <bits/stdc++.h>

using namespace std;

class TicTacToe {
    int n;
    vector<vector<int>> board;

  public:
    TicTacToe(int n){
        this->n = n;
        board.assign(n, vector<int>(n, 0));
    }

    int move(int row, int col, int player){
        board[row][col] = player;

        if (IsRowCrossed(row,player) || IsColCrossed(col,player) || IsDiagonalCrossed(row,col,player)){
            return player;
        }

        return 0; // no winner, yet
    }

    bool IsRowCrossed(int row, int player){
        for(int col=0; col<n; col++){
            if(board[row][col] != player)
                return false;
        }
        return true;
    }

    bool IsColCrossed(int col, int player){
        for(int row=0; row<n; row++){
            if(board[row][col] != player)
                return false;
        }
        return true;
    }


    bool IsDiagonalCrossed(int row, int col, int player){
        if(row == col){
            for(int row=0; row<n; row++){
                if(board[row][row] != player)
                    return false;
            }
        } else if(row == n-col-1){
            for(int row=0; row<n; row++){
                if (board[row][n-row-1] != player)
                    return false;
            }
        }
        return true;
    }
};

int main(){
    cout<<"Tic Tac Toe :-";

    TicTacToe ticTacToe(3);

    cout<<"\nWinner = "<<ticTacToe.move(0, 0, 1); // 0
    cout<<"\nWinner = "<<ticTacToe.move(0, 2, 2); // 0
    cout<<"\nWinner = "<<ticTacToe.move(2, 2, 1); // 0
    cout<<"\nWinner = "<<ticTacToe.move(1, 1, 2); // 0
    cout<<"\nWinner = "<<ticTacToe.move(2, 0, 1); // 0
    cout<<"\nWinner = "<<ticTacToe.move(1, 0, 2); // 0
    cout<<"\nWinner = "<<ticTacToe.move(2, 1, 1); // 1

    return 0;
}