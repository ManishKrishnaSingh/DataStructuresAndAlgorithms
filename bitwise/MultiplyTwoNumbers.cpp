#include <iostream>

using namespace std;

int multiply(int x, int y){
    int result = 0;

    while(y != 0 ){
        if(y & 1){
            result += x;
        }
        x = x << 1;
        y = y >> 1;
    }

    return result;
}

int main(){
    cout << "Multiply[7,5] = " << multiply(7, 5);

    return 0;
}

