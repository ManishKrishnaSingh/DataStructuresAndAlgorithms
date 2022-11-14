#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    bool isLeaf;
    TrieNode* children[26];
    TrieNode(){
        this->isLeaf = false;
        for(int i=0; i<26; i++){
            this->children[i] = nullptr;
        }
    }
};

class MagicDictionary
{
    TrieNode* root;

  public:
    MagicDictionary()
    {
        root = new TrieNode();
    }

    void buildDict(vector<string> dictionary)
    {
        TrieNode* curr = nullptr;
        for(string word : dictionary)
        {
            curr = root;
            for(int i=0; i<word.size(); i++)
            {
                int index = word[i]-'a';
                if(curr->children[index] == nullptr)
                {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->isLeaf = true;
        }
    }

    bool helper(string word)
    {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i]-'a';
            if(curr->children[index] == nullptr)
            {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isLeaf;
    }

    bool search(string word)
    {
        for(int i=0; i<word.size(); i++)
        {
            char ch = word[i];
            for(int j=0; j<26; j++)
            {
                if('a'+j == ch)
                {
                    continue;
                }

                word[i] = 'a'+j;
                if(helper(word))
                {
                    return true;
                }
                word[i] = ch;//reset
            }
        }
        return false;
    }
};

int main(){
    cout<<"Magic Dictionary"<<endl;

    MagicDictionary magicDictionary;

    magicDictionary.buildDict({"hello", "leetcode"});
    
    cout<<boolalpha;
    cout<<magicDictionary.search("hello")<<endl;
    cout<<magicDictionary.search("hhllo")<<endl;
    cout<<magicDictionary.search("hell")<<endl;
    cout<<magicDictionary.search("leetcoded")<<endl;

    return 0;
}