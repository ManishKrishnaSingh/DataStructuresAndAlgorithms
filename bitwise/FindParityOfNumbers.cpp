#include <iostream>

using namespace std;

bool hasOddParity(int x){
    x = x ^ (x >> 1);
    x = x ^ (x >> 2);
    x = x ^ (x >> 4);
    x = x ^ (x >> 8);
    x = x ^ (x >> 16);

    if (x & 1) {
        return true;
    }
    return false;
}

int main(){
    if(hasOddParity(1227)){
        cout<<"Odd Parity\n";
    } else {
        cout<<"Even Parity\n";
    }
    return 0;
}

