#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    findPerfectSquares(1, 100);

    return 0;
}
