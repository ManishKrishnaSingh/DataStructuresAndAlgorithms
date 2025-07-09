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

vector<string> shortestChainLength(vector<string>& dictionary, string start, string finish)
{
    if(start == finish)
    {
        return {start, finish};
    }

    // add start and finish
    dictionary.push_back(start);
    dictionary.push_back(finish);

    unordered_map<string,unordered_set<string>> mapData;
    updateMapOfDictionaryData(dictionary, mapData);

    unordered_set<string> visit;
    priority_queue<vector<string>, vector<vector<string>>, greater<vector<string>>> minHeap;

    minHeap.push({start});
    while(!minHeap.empty())
    {
        auto wordList = minHeap.top(); minHeap.pop();

        if(wordList.back() == finish)
        {
            return wordList;
        }

        visit.insert(wordList.back());
        for(auto str : mapData[wordList.back()])
        {
            if(visit.count(str) == 0)
            {
                wordList.push_back(str);
                minHeap.push({wordList});
            }
        }
    }

    return {};
}

int main()
{
    vector<string> dictionary =
    {
        "poon", "plee", "same", "poie", "plie", "poin", "plea"
    };

    auto wLadder = shortestChainLength(dictionary, "toon", "plea");

    cout<<"Shortest Chain = ";
    for(auto& word : wLadder)
    {
        cout<<" -> "<<word;
    }

    return 0;
}