#include <bits/stdc++.h>

using namespace std;

/***************************************************************************************
Number of Provinces: There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b and city b is connected directly with city c
then city a is connected indirectly with city c. A  province  is  a group of directly or
indirectly connected cities and no other cities outside of the group.
****************************************************************************************/

void dfs(vector<vector<int>>& IsConnected, int& u, int& n, unordered_set<int>& visit)
{
    visit.insert(u);

    for(int v = 0; v < n; v++)
    {
        if((IsConnected[u][v] || IsConnected[v][u])and visit.count(v)==0)
        {
            dfs(IsConnected, v, n, visit);
        }
    }
}

int numberOfProvinces(vector<vector<int>>& IsConnected)
{
    if(IsConnected.size()==0 || IsConnected[0].size()==0)
    {
        return 0;
    }

    unordered_set<int> visit;

    int u, provinceCount=0;
    int n=IsConnected.size();
    for(u = 0; u < n; u++)
    {
        if(visit.count(u) == 0)
        {
            provinceCount++;
            dfs(IsConnected, u, n, visit);
        }
    }

    return provinceCount;
}


int main()
{
    vector<vector<int>> IsConnected =
    {
        {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
    };

    cout<<"Number Of Provinces = "<<numberOfProvinces(IsConnected);

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N)
*************************/