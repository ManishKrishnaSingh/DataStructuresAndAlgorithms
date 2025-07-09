#include <bits/stdc++.h>

using namespace std;

bool IsDifferByOne(string x, string y)
{
    int count=0;
    int n=min(x.size(),y.size());

    for(int i=0; i < n; i++)
    {
        if(x[i] != y[i])
        {
            count++;
        }
    }

    if(count == 1)
    {
        return true;
    }

    return false;
}

void updateMapOfDictionaryData(vector<string>& dictionary, unordered_map<string,unordered_set<string>>& mapData)
{
    int i,j,n=dictionary.size();

    for(i=0; i < n; i++)
    {
        for(j=i+1; j < n; j++)
        {
            if(IsDifferByOne(dictionary[i], dictionary[j]))
            {
                mapData[dictionary[i]].insert(dictionary[j]);
                mapData[dictionary[j]].insert(dictionary[i]);
            }
        }
    }
}

int shortestChainLength(vector<string>& dictionary,string start,string finish)
{
    if(start == finish)
    {
        return 0;
    }

    // add start and finish
    dictionary.push_back(start);
    dictionary.push_back(finish);

    unordered_map<string,unordered_set<string>> mapData;
    updateMapOfDictionaryData(dictionary, mapData);

    unordered_set<string> visit;
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;

    pq.push({1, start});
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();

        auto& dist = top.first;
        auto& word = top.second;

        if(word == finish)
        {
            return dist;
        }

        visit.insert(word);

        for(auto str : mapData[word])
        {
            if(visit.count(str) == 0)
            {
                pq.push({dist+1, str});
            }
        }
    }

    return 0;
}

int main(){
    vector<string> dictionary =
    {
        "poon", "plee", "same", "poie", "plie", "poin", "plea"
    };

    int ladderLength = shortestChainLength(dictionary, "toon", "plea");
    cout<<"Shortest Chain Length [Dictionary] = "<<ladderLength<<endl;

    return 0;
}