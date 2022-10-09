#include <bits/stdc++.h>

using namespace std;

int minSwapsToBalance(string iStr){
    int maxClose = 0, xtraClose = 0;
    //find xtra and maximum close count
    for(int i=0; i<iStr.length(); i++){
        if(iStr[i] == '['){
            xtraClose -= 1;
        } else {
            xtraClose += 1;
        }
        // update maximum close count
        maxClose = max(maxClose, xtraClose);
    }
    return ceil((double)maxClose/2);
}

int main() {
    int minSwaps=minSwapsToBalance("[]][][");
    cout<<"min swaps to balance = "<<minSwaps;
    return 0;
}