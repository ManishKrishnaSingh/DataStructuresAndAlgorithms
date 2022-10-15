#include <bits/stdc++.h>

using namespace std;

/*************************************************************************
In an array prices where price[i] is price of a given stock on the ith day.
Find maximum profit you can achieve. You may complete at most k transaction

Note: You may not engage in multiple transactions simultaneously (i.e., you
must sell the stock before you buy again).
**************************************************************************/

int maxProfitStockBuySell(int price[], int n, int k){
    int profit[k+1][n+1];

    //set profit to 0 if day 0
    for(int i=0; i <= k; i++){
        profit[i][0] = 0;
    }
    //set profit to 0 if k == 0
    for(int j=0; j <= n; j++){
        profit[0][j] = 0;
    }

    //update profit bottom-up
    for(int i=1; i<=k; i++){
        int prevProfit = INT_MIN;
        for (int j=1; j<n; j++) {
            prevProfit = max(prevProfit, profit[i-1][j-1]-price[j-1]);
            profit[i][j] = max(profit[i][j-1], price[j] + prevProfit);
        }
    }

    return profit[k][n-1];
}

int main(){
    int k = 2;
    int price[] = { 3, 3, 5, 0, 0, 3, 1, 4 };
    int n = sizeof(price) / sizeof(price[0]);

    int maxProfit = maxProfitStockBuySell(price, n, k);
    cout<<"Max Profit[Stock Buy & Sell]="<<maxProfit;

    return 0;
}