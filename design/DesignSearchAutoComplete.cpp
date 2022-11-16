#include <bits/stdc++.h>

using namespace std;

class compare
{
  public:
    bool operator()(const pair<int,string> &a, const pair<int, string> &b)
    {
        return a.first > b.first || a.first == b.first && a.second < b.second;
    }
};

struct TrieNode
{
    int frequency;
    map<char,TrieNode*> children;
    TrieNode()
    {
        this->frequency = 0;
    }
};

class AutocompleteSystem
{
    string prefix = "";
    TrieNode* root = nullptr;
    TrieNode* curr = nullptr;
    // priority queue of pair of {sentence, frequency}
    priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pQueue;

  public:
    AutocompleteSystem(vector<string> sentences, vector<int> times)
    {
        TrieNode* node = new TrieNode();
        this->root = this->curr = node;
        for(int i=0;i<times.size();i++)
        {
            // trie insert : sentence+freq
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char ch)
    {
        // last chars
        if(ch == '#')
        {
            curr = root;
            insert(prefix, 1);
            prefix = "";
            return {};
        }

        // middle char
        prefix += ch;
        if(curr == nullptr)
        {
            return {};
        }

        return search(curr, ch);
    }

  private:
    void insert(string word, int ifrequency)
    {
        TrieNode* node = root;
        for(char ch : word)
        {
            if(node->children.count(ch) == 0)
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->frequency += ifrequency;
    }

    void dfsSearch(TrieNode* node, string iStr)
    {
        if(node->frequency)
        {
            if(pQueue.size()==3 && pQueue.top().first < node->frequency)
            {
                pQueue.pop();
                pQueue.push({node->frequency, iStr});
            }
            if(pQueue.size() < 3)
            {
                pQueue.push({node->frequency, iStr});
            }
        }

        for(auto child: node->children)
        {
            dfsSearch(child.second, iStr+child.first);
        }
    }

    vector<string> search(TrieNode* node, char ch)
    {
        vector<string> result;
        if(node->children.find(ch)==node->children.end())
        {
            curr = NULL;
            return result;
        }

        curr = node->children[ch];
        dfsSearch(curr, prefix);

        pair<int,string> top;
        while(!pQueue.empty())
        {
            top=pQueue.top();pQueue.pop();
            result.push_back(top.second);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    cout<<"Search Autocomplete System"<<endl;

    vector<string> sentences =
    {
        "i love you", "island", "iroman", "i love leetcode"
    };
    vector<int> frequency = {5, 3, 2, 2};

    AutocompleteSystem autoCompleteSys(sentences, frequency);

    autoCompleteSys.input('i');
    autoCompleteSys.input(' ');
    autoCompleteSys.input('a');
    autoCompleteSys.input('#');

    return 0;
}