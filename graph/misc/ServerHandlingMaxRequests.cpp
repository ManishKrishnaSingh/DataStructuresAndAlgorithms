// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/?envType=problem-list-v2&envId=7p55wqm

#include <bits/stdc++.h>

using namespace std;

vector<int> FindBusiestServers(int k, vector<int>& arrival, vector<int>& load)
{
    // Init available servers
    set<int> availableServers;
    for (int i = 0; i < k; ++i)
    {
        availableServers.insert(i);
    }

    // Priority queue to manage busy servers based on their end time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;

    // Requests handled by servers
    vector<int> requestCount(k, 0);

    // Iterate over each request
    for (int i = 0; i < arrival.size(); ++i)
    {
        int startTime = arrival[i];
        int endTime = startTime + load[i];

        // Free up servers that have completed their tasks
        while (!busyServers.empty() && busyServers.top().first <= startTime)
        {
            availableServers.insert(busyServers.top().second);
            busyServers.pop();
        }

        // Skip to the next request
        if (availableServers.empty())
        {
            continue;
        }

        // Find the first server that can take the current request
        auto serverIterator = availableServers.lower_bound(i % k);
        if (serverIterator == availableServers.end())
        {
            serverIterator = availableServers.begin();
        }

        // Assign the task to the server
        int assignedServer = *serverIterator;
        ++requestCount[assignedServer];
        busyServers.emplace(endTime, assignedServer);

        // Remove the server from the available set as it's now busy
        availableServers.erase(assignedServer);
    }

    // Find the maximum number of requests handled by any server
    int maxRequests = *max_element(requestCount.begin(), requestCount.end());

    // Collect all servers that handled the max number of requests
    vector<int> busiestServers;
    for (int i = 0; i < k; ++i)
    {
        if (requestCount[i] == maxRequests)
        {
            busiestServers.push_back(i);
        }
    }

    return busiestServers;
}

int main() {
    int k = 3;

    vector<int> arrival = {1,2,3,4,5};
    vector<int> load =    {5,2,3,3,3};

    auto busiestServers = FindBusiestServers(k, arrival, load);
    for(auto& idxBusiestServer: busiestServers)
    {
        cout<<"Busiest Server Index = "<<idxBusiestServer<<endl;
    }

    cout<<endl;

    arrival = {1,2,3,4}; load = {1,2,1,2};
    busiestServers = FindBusiestServers(k, arrival, load);
    for(auto& idxBusiestServer: busiestServers)
    {
        cout<<"Busiest Server Index = "<<idxBusiestServer<<endl;
    }

    cout<<endl;

    arrival = {1,2,3}; load = {10,12,11};
    busiestServers = FindBusiestServers(k, arrival, load);
    for(auto& idxBusiestServer: busiestServers)
    {
        cout<<"Busiest Server Index = "<<idxBusiestServer<<endl;
    }

    return 0;
}
