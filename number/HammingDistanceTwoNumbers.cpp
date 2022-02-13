#include <iostream>

using namespace std;

int findHammingDistance(int x, int y){
    int num = x^y;

    int bitcount = 0;
    while(num>0){
        bitcount += num & 1;
        num = num >> 1;
    }

    return bitcount;
}

int main(){
    int x = 4, y = 8;
    int distance = findHammingDistance(x, y);
    cout<<"Hamming Distance [4,8] = "<<distance;
    return 0;
}

