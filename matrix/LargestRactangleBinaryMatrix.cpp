#include <stack>
#include <iostream>

using namespace std;

#define R 4
#define C 4

int maxHist(int row[]){
    stack<int> stk;

    int stkTop;
    int areaWithStkTop = 0;
    int areaMaxRectangle = 0;

    int i = 0;
    while (i < C) {
        if (stk.empty() || row[stk.top()] <= row[i]){
            stk.push(i++);
        } else {
            stkTop = stk.top(); stk.pop();
            areaWithStkTop = row[stkTop] * (stk.empty()? i : (i-stk.top()-1));
            areaMaxRectangle = max(areaWithStkTop, areaMaxRectangle);
        }
    }

    while (!stk.empty()) {
        stkTop = stk.top(); stk.pop();
        areaWithStkTop = row[stkTop] * (stk.empty()? i : (i-stk.top()-1));
        areaMaxRectangle = max(areaWithStkTop, areaMaxRectangle);
    }

    return areaMaxRectangle;
}

int maxRectangle(int MAT[R][C]){
    int result = maxHist(MAT[0]);
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++){
            if (MAT[i][j] == 1){
                MAT[i][j] += MAT[i-1][j];
            }
        }
        result = max(result, maxHist(MAT[i]));
    }
    return result;
}

int main(){
    int MAT[R][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area [Largest Rectangle] = "<< maxRectangle(MAT);

    return 0;
}

