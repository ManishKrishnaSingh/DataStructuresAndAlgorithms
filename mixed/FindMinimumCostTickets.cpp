#include <bits/stdc++.h>

using namespace std;

int minCostTickets(vector<int>& days, vector<int>& costs){
    unordered_set<int> hash;
    for(int day : days){
        hash.insert(day);
    }

    int lastday = days.back();
    int dp[lastday+1];

    dp[0] = 0; // base case
    for(int i=1; i<=lastday; i++){
        // update prev day cost & cont.
        if(hash.find(i) == hash.end()){
            dp[i] = dp[i-1]; continue;
        }

        // 1-day pass cost
        dp[i] = dp[i-1]+costs[0];
        // 7-day pass cost
        dp[i] = min(dp[max(i-7,0)]+costs[1], dp[i]);
        // 30-day pass cost
        dp[i] = min(dp[max(i-30,0)]+costs[2], dp[i]);
    }

    return dp[lastday];
}

int main() {
    vector<int> cost = {2,7,15};
    vector<int> days = {1,4,6,7,8,20};
    
    int costTickets = minCostTickets(days, cost);
    cout<<"Minimum Tickets Cost = "<<costTickets;

    return 0;
}