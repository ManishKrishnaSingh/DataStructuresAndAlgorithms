#include <bits/stdc++.h>

using namespace std;

#define R 3
#define C 3

int findUniquePathsInGrid(int mat[R][C]){
    if(mat[0][0]==1 || mat[R-1][C-1]==1){
        return 0;
    }

    int i,j;

    // init
    mat[0][0] = 1;
    for(i=1; i<R; i++){
        if(mat[i][0] == 0){
            mat[i][0] = mat[i-1][0];
        } else {
            mat[i][0] = 0;
        }
    }
    for(j=1; j<C; j++){
        if(mat[0][j] == 0){
            mat[0][j] = mat[0][j-1];
        } else {
            mat[0][j] = 0;
        }
    }

    for(i=1; i<R; i++){
        for(j=1; j<C; j++){
            if (mat[i][j] == 0) {
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            } else {
                mat[i][j] = 0;
            }
        }
    }

    return mat[R-1][C-1];
}

int main(){
    int mat[R][C] = {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 }
    };

    int nUniquePaths = findUniquePathsInGrid(mat);
    cout<<"Count [Unique Paths] = "<<nUniquePaths;

    return 0;
}

