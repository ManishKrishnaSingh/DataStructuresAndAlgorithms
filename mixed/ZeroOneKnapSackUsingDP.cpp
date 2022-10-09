#include <bits/stdc++.h>

using namespace std;

//Item -> { Weight, Value }
typedef pair<int,int> Item;

int knapSack(vector<Item> items, int weight){
    int dp[weight+1];
    memset(dp,0,sizeof(dp));

    int n = items.size();
    int wtOfItem, vlOfItem;

    for(int i=1; i<=n; i++){
        wtOfItem = items[i-1].first;
        vlOfItem = items[i-1].second;
        for (int w=weight; w>=0; w--){
            if (wtOfItem <= w){
                dp[w] = max(dp[w], dp[w-wtOfItem] + vlOfItem);
            }
        }
    }

    return dp[weight];
}

int main()
{
    //Sack Capacity
    int weight = 50;
    
    //List of {Weight,Value}
    vector<Item> items = {
        {10,60}, {20,100}, {30,120}
    };
    
    int maxValue = knapSack(items, weight);
    cout<<"Max KnapSack Value = "<<maxValue;

    return 0;
}
