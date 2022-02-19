#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

class LruCache {
  private:
    int capacity;
    list<int> qCache;
    unordered_map<int, list<int>::iterator> mIdToIter;

  public:
    LruCache(int iCapacity){
        capacity = iCapacity;
    }

    void refer(int id){
        // not present in cache
        if (mIdToIter.find(id) == mIdToIter.end())
        {
            // cache is full
            if (qCache.size() == capacity) {
                // delete least recently used element
                int last = qCache.back();

                // Pops the last element
                qCache.pop_back();

                // Erase the last
                mIdToIter.erase(last);
            }
        } else {
            // present in cache
            qCache.erase(mIdToIter[id]);
        }

        // update reference
        qCache.push_front(id);
        mIdToIter[id] = qCache.begin();
    }

    void display(){
        for (auto it = qCache.begin(); it != qCache.end(); it++){
            cout << (*it) << " ";
        }
        cout << endl;
    }
};

int main(){
    LruCache lruCache(4);

    // refer cache
    lruCache.refer(1);
    lruCache.refer(2);
    lruCache.refer(3);
    lruCache.refer(1);
    lruCache.refer(4);
    lruCache.refer(5);

    // display cache
    lruCache.display();

    return 0;
}

