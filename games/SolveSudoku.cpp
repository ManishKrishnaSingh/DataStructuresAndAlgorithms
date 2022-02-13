#include <iostream>

using namespace std;

#define N 9

void PrintSudoku(int grid[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool IsSolved(int grid[N][N], int& row, int& col){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == 0){
                row=i; col=j;
                return false;
            }
        }
    }
    return true;
}

bool UsedInRow(int grid[N][N], int row, int num){
    for(int col=0; col<N; col++){
        if(grid[row][col]==num){
            return true;
        }
    }
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num){
    for(int row=0; row<N; row++){
        if(grid[row][col]==num){
            return true;
        }
    }
    return false;
}

bool UsedInBox(int grid[N][N], int row, int col, int num){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[row+i][col+j] == num){
                return true;
            }
        }
    }
    return false;
}

bool IsSafe(int grid[N][N], int r, int c, int num){
    return !UsedInRow(grid,r,num) && !UsedInCol(grid,c,num) && !UsedInBox(grid,r-r%3,c-c%3,num) && grid[r][c]==0;
}

bool solveSudoku(int grid[N][N]){
	int row, col;
	if (IsSolved(grid, row, col)){
	    return true;
	}

	for(int num=1; num<= 9; num++){
	    if (IsSafe(grid, row, col, num)){
	        grid[row][col] = num;
	        // Return, if success
	        if (solveSudoku(grid)){
	            return true;
	        }
	        grid[row][col] = 0;
	    }
	}
	return false;
}

int main(){
    int grid[N][N] = {
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };

    if(solveSudoku(grid)){
        PrintSudoku(grid);
    } else {
        cout<<"No solution!";
    }

    return 0;
}

