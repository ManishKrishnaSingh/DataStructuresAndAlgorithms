#include <bits/stdc++.h>

using namespace std;

/***********************************************************************
Choose a single day to buy one stock & choose a different day to sell it
************************************************************************/

int maxProfitStockBuySell(int price[], int n){
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int i=0; i<n; i++) {
        if (price[i] < minPrice){
            minPrice = price[i];
        } else if(maxProfit < (price[i]-minPrice)){
            maxProfit = (price[i]-minPrice);
        }
    }
    return maxProfit;
}

int main(){
    int price[]={100,180,260,310,40,535,695};
    int n = sizeof(price) / sizeof(price[0]);

    int maxProfit = maxProfitStockBuySell(price, n);
    cout<<"Max Profit[Stock Buy & Sell]="<<maxProfit;

    return 0;
}