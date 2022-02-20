#include <iostream>
#include <algorithm>

using namespace std;

int maxCoins(int piles[], int n) {
    sort(piles, piles+n);

    int nCoins=0;
    for(int i=n/3; i<n; i=i+2){
        nCoins += piles[i];
    }

    return nCoins;
}

int main() {
    int arr[] = { 9,8,7,6,5,1,2,3,4 };
    int n = sizeof(arr) / sizeof(int);
    cout<<"Maximum Coins = "<<maxCoins(arr,n);
    return 0;
}

