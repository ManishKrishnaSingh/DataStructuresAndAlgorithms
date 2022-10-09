#include <bits/stdc++.h>

using namespace std;

void findLastOpenDoors(){
    int doors[101];
    int i, index, multi;

    //visit of first monkey
    for(i=1; i<=100; i++){
        doors[i] = 1;
    }

    // let monkeys open/close
    for(i=2; i<=100; i++){
        multi = 1;
        index = i * multi++;
        while(index <= 100){
            doors[index]++;
            index = i*multi++;
        }
    }

    // final open doors are
    cout<<"Open Doors are: ";
    for(i=1; i<=100; i++){
        if(doors[i]%2 == 1){
            cout<<i<<" ";
        }
    }
}

void findPerfectSquares(double left, double right){
    int num = ceil(sqrt(left));

    // first number's square
    int square = num*num;

    // next number difference
    int difference = (num*2)+1;

    // print perfect squares
    while(square <= right){
        cout << square << " ";
        square += difference;
        // update the difference
        difference = difference+2;
    }
}

int main(){
    // Solution 1 :
    findLastOpenDoors();

    // Solution 2 :
    cout<<"\nOpen Doors are: ";
    findPerfectSquares(1, 100);

    return 0;
}