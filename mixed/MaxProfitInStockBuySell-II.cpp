#include <bits/stdc++.h>

using namespace std;

/*************************************************************************
In an array prices where price[i] is price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold
at most 1 share of stock at any time & you can buy it then immediately sell
it on the same day. Return the maximum profit you can achieve.
**************************************************************************/

int maxProfitStockBuySell(int price[], int n){
    int maxProfit = 0;
    if(n >= 2){
        int idx=0;
        while(idx < n-1) {
            while((idx < n-1) && (price[idx+1] <= price[idx])){
                idx++;
            }

            if(idx == n-1){
                break;
            }

            int idxBuy = idx++;
            while((idx < n) && (price[idx] >= price[idx-1])){
                idx++;
            }
            int idxSell = idx-1;

            maxProfit += (price[idxSell] - price[idxBuy]);
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