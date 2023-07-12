#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
You have planned some train traveling one year in advance. The days of the year in which you
will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:
	-  1-day pass is sold for costs[0] dollars
	-  7-day pass is sold for costs[1] dollars
	- 30-day pass is sold for costs[2] dollars

The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2,3,4,5,6,7 & 8

Return the minimum number of dollars you need to travel every day in the given list of days.
********************************************************************************************/

int minCostTickets(vector<int>& days, vector<int>& costs){
    unordered_set<int> hash;
    for(int day : days)
    {
        hash.insert(day);
    }

    int lastday = days.back();
    int dp[lastday+1];

    dp[0] = 0; // base case
    for(int i=1; i<=lastday; i++)
    {
        // update prev day cost & cont.
        if(hash.find(i) == hash.end())
        {
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

int main()
{
    vector<int> cost = {2,7,15};
    vector<int> days = {1,4,6,7,8,20};
    
    int costTickets = minCostTickets(days, cost);
    cout<<"Minimum Tickets Cost = "<<costTickets;

    return 0;
}

/****************************
Time Complexity  : O(LastDay)
Space Complexity : O(LastDay)
*****************************/
