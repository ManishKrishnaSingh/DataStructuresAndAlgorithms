#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int index;
    map<int, TrieNode*> mChildren;
    TrieNode(){
        this->index = -1;
    }
};

class WordFilterTrie {
    TrieNode* root;

  public:
    WordFilterTrie(vector<string> words){
        root = new TrieNode();
        TrieNode* curr = nullptr;
        TrieNode* temp = nullptr;

        int diffch = 'a'-1;
        int nWords = words.size();

        for(int i=0; i<nWords; i++){
            curr = root;
            curr->index = i;

            string word = words[i];
            int wLength = word.size();
            for(int i=0; i<wLength; ++i){
                temp = curr;
                for(int j=i; j<wLength; ++j){
                    int code = (word[j] - diffch) * 27;
                    if (temp->mChildren[code] == nullptr){
                        temp->mChildren[code] = new TrieNode();
                    }
                    temp = temp->mChildren[code];
                    temp->index = i;
                }

                temp = curr;
                for (int k=wLength-1-i; k >= 0; --k){
                    int code = (word[k] - diffch);
                    if (temp->mChildren[code] == nullptr){
                        temp->mChildren[code] = new TrieNode();
                    }
                    temp = temp->mChildren[code];
                    temp->index = i;
                }

                int code = (word[i]-diffch)*27 + (word[wLength-1-i]-diffch);
                if (curr->mChildren[code] == nullptr){
                    curr->mChildren[code]= new TrieNode();
                }
                curr = curr->mChildren[code];
                curr->index = i;

            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* curr = root;

        char xCh, yCh;
        int diffch = 'a'-1;

        int i=0, j=suffix.length()-1;
        while(i<prefix.length() || j>=0)
        {
            xCh = yCh = diffch;
            if(i < prefix.length()){
                xCh = prefix[i];
            }
            if(j >= 0){
                yCh = suffix[j];
            }

            int code = (xCh-diffch)*27 + (yCh-diffch);
            curr = curr->mChildren[code];
            if (curr == nullptr){
                return -1;
            }
            i++; j--;
        }

        return curr->index;
    }
};


class WordFilterHash {
    // map of {Prefix|Suffix and word index}
    unordered_map<string, int> mPrefixSuffix;

  public:
    WordFilterHash(vector<string> words){
        int nWords = words.size();
        string prefix, suffix, word;
        for(int i=0; i<nWords; i++){
            word = words[i]; // input word
            for(int j=1; j<=word.size(); j++){
                prefix = word.substr(0, j);
                for(int k=0; k<word.size(); k++){
                    suffix = word.substr(k);
                    mPrefixSuffix[prefix+"|"+suffix] = (i+1);
                }
            }
        }
    }
    int f(string prefix, string suffix){
        return mPrefixSuffix[prefix+"|"+suffix]-1;
    }
};

int main(){
    cout<<"Prefix and Suffix\n";
    vector<string> dictionary = {
        "apple", "alpine", "amazon"
    };

    WordFilterTrie wfTrie(dictionary);
    cout<<"\nIndex = "<<wfTrie.f("a", "ne");

    WordFilterHash wfHash(dictionary);
    cout<<"\nIndex = "<<wfHash.f("am", "n");

    return 0;
}