#include <bits/stdc++.h>

using namespace std;

#define ROW 4
#define COL 4

void PrintMatrix(int matrix[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Transpose(int matrix[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=i+1; j<COL; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main(){
    int matrix[ROW][COL]={
        { 1,   2,  3,  4 },
        { 5,   6,  7,  8 },
        { 9,  10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    cout<<"Matrix:\n";
    PrintMatrix(matrix);

    cout<<"\nMatrix:\n";
    Transpose(matrix);
    PrintMatrix(matrix);

    return 0;
}

