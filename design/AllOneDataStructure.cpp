#include <bits/stdc++.h>

using namespace std;

class AllOne {
    set<pair<int,string>> sCountKey;
    unordered_map<string,int> mKeyCount;

  public:
    AllOne(){
        sCountKey.clear();
        mKeyCount.clear();
    }

    void inc(string iKey){
        if(mKeyCount.count(iKey)){
            // erase older entry & add new entry with +1 frequency
            sCountKey.erase(sCountKey.find({mKeyCount[iKey],iKey}));
            sCountKey.insert({mKeyCount[iKey]+1, iKey});
        } else {
            // add key with frequency 1
            sCountKey.insert({1, iKey});
        }

        mKeyCount[iKey]++; //increase key frequency in map
    }

    void dec(string iKey){
        if(mKeyCount.count(iKey)){
            // find entry in set and erase older entry from the set
            sCountKey.erase(sCountKey.find({mKeyCount[iKey], iKey}));

            if(mKeyCount[iKey] > 1){
                // frequency > 1
                mKeyCount[iKey]--;
                sCountKey.insert({mKeyCount[iKey], iKey});
            } else {
                // frequency == 1
                mKeyCount.erase(iKey);
            }
        }
    }

    string getMinKey(){
        string key = "";
        if(sCountKey.size() > 0){
            key = sCountKey.begin()->second;
        }
        return key;
    }

    string getMaxKey(){
        string key = "";
        if(sCountKey.size() > 0){
            key = sCountKey.rbegin()->second;
        }
        return key;
    }
};

int main()
{
    cout<<"All One DS"<<endl;

    AllOne* allOne = new AllOne();

    allOne->inc("abc");
    allOne->inc("xyz");
    allOne->inc("xyz");
    allOne->inc("xyz");
    allOne->dec("xyz");
    allOne->inc("bcd");
    
    cout<<"Min Key: "<<allOne->getMinKey()<<endl;
    cout<<"Max Key: "<<allOne->getMaxKey()<<endl;

    return 0;
}