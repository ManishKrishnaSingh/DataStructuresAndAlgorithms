#include <iostream>

using namespace std;

#define ROW 4
#define COL 4

void printMatrix(int matrix[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printSpiral(int matrix[ROW][COL], int RB, int RE, int CB, int CE){
    if (RB >= RE or CB >= CE){
        return;
    }

    for(int C=CB; C<CE; C++){
        cout<<matrix[RB][C]<<" ";
    }

    for(int R=RB+1; R<RE; R++){
        cout<<matrix[R][CE-1]<<" ";
    }

    for(int C=CE-2; C>=CB; C--){
        cout<<matrix[RE-1][C]<<" ";
    }

    for(int R=RE-2; R>RB; R--){
        cout<<matrix[R][CB]<<" ";
    }

    printSpiral(matrix, RB+1, RE-1, CB+1, CE-1);
}

int main(){
    int matrix[ROW][COL]={
        { 1,   2,  3,  4 },
        { 5,   6,  7,  8 },
        { 9,  10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    cout<<"Matrix:\n";
    printMatrix(matrix);

    cout<<"\nSpiral:";
    printSpiral(matrix, 0, ROW, 0, COL);

    return 0;
}

