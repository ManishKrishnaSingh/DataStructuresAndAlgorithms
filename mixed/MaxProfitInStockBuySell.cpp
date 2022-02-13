#include <iostream>

using namespace std;

int maxProfitStockBuySell(int price[], int n){
    int profit=0;
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

            profit += (price[idxSell]-price[idxBuy]);
        }
    }
    return profit;
}

int main(){
    int price[]={100,180,260,310,40,535,695};
    int n = sizeof(price) / sizeof(price[0]);

    int maxProfit = maxProfitStockBuySell(price, n);
    cout<<"Max Profit [Stock Buy & Sell] = "<<maxProfit;

    return 0;
}

