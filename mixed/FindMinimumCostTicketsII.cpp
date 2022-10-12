#include <bits/stdc++.h>

using namespace std;

vector<int> durations = {1,7,30};

int minCostUtil(int index, int dp[], vector<int>& days, vector<int>& costs){
    int n = days.size();

    if(index >= n){
        return 0;
    }

    if(dp[index] > 0){
        return dp[index];
    }

    int j = index;
    int currCost, minCost=INT_MAX;
    for(int k=0; k<3; k++) {
        while(j<n && days[j]<(days[index]+durations[k])){
            j++;
        }
        currCost = minCostUtil(j,dp,days,costs) + costs[k];
        minCost = min(minCost,currCost); // update mincost
    }

    return dp[index] = minCost;
}

int minCostTickets(vector<int>& days, vector<int>& costs){
    int dp[days.size()];
    memset(dp,0,sizeof(dp));

    return minCostUtil(0,dp,days,costs);
}

int main() {
    vector<int> cost = {2,7,15};
    vector<int> days = {1,4,6,7,8,20};
    
    int costTickets = minCostTickets(days, cost);
    cout<<"Minimum Tickets Cost = "<<costTickets;

    return 0;
}