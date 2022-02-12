#include <set>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int,int> mypair;

class compare{
  public:
    bool operator()(const mypair& left, const mypair& right){
        if(left.second != right.second){
            return left.second > right.second;
        }
        return left.first > right.first;
    }
};

class Data {
  private:
    int info;
  public:
    Data(int iInfo){
        info = iInfo;
    }
    void print(){
        cout<<"DATA # "<<info<<endl;
    }
};

class LfuCache {
  private:
    int capacity;

    unordered_map<int, Data*> mIdToData;
    unordered_map<int, int>   mIdToFrequency;

    set<mypair, compare> sIdByFrequency;

  public:
    LfuCache(int iCapacity){
        capacity = iCapacity;
    }

    Data* Get(int id){
        // check if it is found in map
        if(mIdToFrequency.find(id) != mIdToFrequency.end())
        {
            // erase it from idByFrequency
            auto it = sIdByFrequency.find({id, mIdToFrequency[id]});
            sIdByFrequency.erase(it);

            //increase the frequency
            mIdToFrequency[id]++;

            // add back to the idByFrequency
            sIdByFrequency.insert({id, mIdToFrequency[id]});

            // return data for id
            return mIdToData[id];
        }
        return nullptr;
    }

    void Put(int id, Data* data){
        // check if it is found in map
        if(mIdToFrequency.find(id) == mIdToFrequency.end())
        {
            if(sIdByFrequency.size() == capacity){
                // get min frequency pair
                auto minFrequency = sIdByFrequency.begin();

                //remove id with min frequency
                sIdByFrequency.erase(minFrequency);

                //remove from id to data
                mIdToData.erase(minFrequency->first);

                //remove from id to frequency
                mIdToFrequency.erase(minFrequency->first);
            }

            // insert with frequency 1
            mIdToFrequency[id] = 1;

            // insert the id+frequency in heap
            sIdByFrequency.insert({id, mIdToFrequency[id]});
        }

        mIdToData[id] = data; // insert/update id Data
    }
};

int main(){
    LfuCache lfuCache(5);

    // Put into lfuCache
    lfuCache.Put(1, new Data(1000));
    lfuCache.Put(2, new Data(2000));
    lfuCache.Put(2, new Data(2500));
    lfuCache.Put(3, new Data(3000));
    lfuCache.Put(3, new Data(3500));
    lfuCache.Put(4, new Data(4000));
    lfuCache.Put(4, new Data(4500));
    lfuCache.Put(5, new Data(5000));
    lfuCache.Put(5, new Data(5500));
    lfuCache.Put(6, new Data(6000));
    lfuCache.Put(6, new Data(6800));

    // Get from lfuCache
    Data* data = nullptr;

    data = lfuCache.Get(1);
    if(data != nullptr){
        data->print();
    }

    data = lfuCache.Get(2);
    if(data != nullptr){
        data->print();
    }

    data = lfuCache.Get(2);
    if(data != nullptr){
        data->print();
    }

    data = lfuCache.Get(5);
    if(data != nullptr){
        data->print();
    }

    data = lfuCache.Get(6);
    if(data != nullptr){
        data->print();
    }

    return 0;
}
