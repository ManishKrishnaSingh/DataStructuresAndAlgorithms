#include <bits/stdc++.h>

using namespace std;

/******************************************************************************
Input accounts = [
    ["John", "johnsmith@mail.com", "john00@mail.com"],
    ["John", "johnnybravo@mail.com"],
    ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
    ["Mary", "mary@mail.com"]
]
Output accounts = [
    ["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
    ["John", "johnnybravo@mail.com"],
    ["Mary", "mary@mail.com"]
]
******************************************************************************/

string find(string idStr, unordered_map<string,string>& parent){
    return parent[idStr] == idStr ? idStr : find(parent[idStr], parent);
}

void accountsMergeUnionFind(vector<vector<string>>& accounts){
    unordered_map<string, string> mOwners;
    unordered_map<string, string> mParent;

    unordered_map<string, set<string>> mUnions;

    // init owner and parent map
    for(int i=0; i<accounts.size(); i++){
        for(int j=1; j<accounts[i].size(); j++){
            mOwners[accounts[i][j]] = accounts[i][0];
            mParent[accounts[i][j]] = accounts[i][j];
        }
    }

    // update parent map for each account
    for(int i=0; i<accounts.size(); i++){
        string parent = find(accounts[i][1], mParent);
        for(int j=2; j<accounts[i].size(); j++){
            mParent[find(accounts[i][j], mParent)] = parent;
        }
    }

    // merge union map using parent map
    for(int i=0; i<accounts.size(); i++){
        for (int j=1; j<accounts[i].size(); j++){
            mUnions[find(accounts[i][j], mParent)].insert(accounts[i][j]);
        }
    }

    // print merged accounts
    for(auto data : mUnions){
        cout<<"\n["<<mOwners[data.first]<<"]: ";
        for(auto idEmail : data.second){
            cout << idEmail << "; ";
        }
    }
}

int main() {
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    accountsMergeUnionFind(accounts);

    return 0;
}