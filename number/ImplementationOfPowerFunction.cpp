#include <iostream>

using namespace std;

int power(int x, int y){
    if(x == 0){
        return 0;
    }
    if(y == 0){
        return 1;
    }

    int result=1;
    while(y != 0){
        if(y%2 == 1){
            y--;
            result = result*x;
        } else {
            y = y >> 1;
            result = result*x*x;
        }
    }
    return result;
}

int main(){
    int x = 4, y = 3;

    cout<<"POWER[X,Y] = "<<power(x,y);

    return 0;
}

