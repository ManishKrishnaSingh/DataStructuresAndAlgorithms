#include <vector>
#include <iostream>

using namespace std;

#define ROW 5
#define COL 4

void printMatrix(int matrix[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printZigZag(int matrix[ROW][COL]){
    vector<vector<int>> diagonal(ROW+COL-1);
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            diagonal[i+j].push_back(matrix[i][j]);
        }
    }

    for(int i=0; i<diagonal.size(); i++){
        for(int j=diagonal[i].size()-1; j>=0; j--){
            if(i%2==0){
                cout<<diagonal[i][j]<<" ";
            } else {
                cout<<diagonal[i][diagonal[i].size()-1-j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int matrix[ROW][COL]={
        { 1,   2,  3,  4 },
        { 5,   6,  7,  8 },
        { 9,  10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 },
    };

    cout<<"Matrix:\n";
    printMatrix(matrix);

    cout<<"\nDiagonal:\n";
    printZigZag(matrix);

    return 0;
}

