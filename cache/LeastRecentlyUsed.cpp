#include <bits/stdc++.h>

using namespace std;

class LruCache {
    int capacity;
    list<int> keyQueue;
    unordered_map<int,int> mKeyToVal;
    unordered_map<int, list<int>::iterator> mKeyToItr;

  public:
    LruCache(int iCapacity){
        capacity = iCapacity;
    }

    int get(int key){
        if (mKeyToItr.count(key)){
            // brings the key to the front in the queue
            keyQueue.splice(keyQueue.begin(), keyQueue, mKeyToItr[key]);
            // erase existing key
            //keyQueue.erase(mKeyToItr[key]);
            // push to front in queue
            //keyQueue.push_front(key);
            // update iterator map
            mKeyToItr[key] = keyQueue.begin();
            // return value 4 key
            return mKeyToVal[key];
        }
        return -1;
    }

    void put(int key, int value){
        if (mKeyToItr.count(key)){
            keyQueue.erase(mKeyToItr[key]);
        } else if (keyQueue.size() == capacity){
            // delete the last used key
            int lastKey = keyQueue.back();
            keyQueue.pop_back();
            // erase the last key
            mKeyToItr.erase(lastKey);
            mKeyToVal.erase(lastKey);
        }
        // update the reference
        keyQueue.push_front(key);
        mKeyToVal[key] = value;
        mKeyToItr[key] = keyQueue.begin();
    }
};

int main(){
    LruCache lruCache(2);

    lruCache.put(1, 10);
    lruCache.put(2, 20);
    cout<<"\n=> "<<lruCache.get(1); // 10

    lruCache.put(3, 30);
    cout<<"\n=> "<<lruCache.get(2); // -1

    lruCache.put(4, 40);
    cout<<"\n=> "<<lruCache.get(1); // -1
    cout<<"\n=> "<<lruCache.get(3); // 30
    cout<<"\n=> "<<lruCache.get(4); // 40

    return 0;
}