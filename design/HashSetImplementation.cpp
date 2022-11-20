#include <bits/stdc++.h>

using namespace std;

class Bucket
{
    vector<int> bucket;

  public :
    Bucket()
    {
        //TODO:
    }

    void add(int iKey)
    {
        bool keyExistInBucket = false;
        for(auto item : this->bucket)
        {
            if(item == iKey)
            {
                keyExistInBucket = true;
            }
        }
        if (keyExistInBucket == false)
        {
            this->bucket.push_back(iKey);
        }
    }

    void remove(int iKey)
    {
        for(auto item : this->bucket)
        {
            if(item == iKey)
            {
                this->bucket.erase(find(bucket.begin(),bucket.end(),item)); break;
            }
        }
    }

    bool contains(int iKey)
    {
        for(auto item : this->bucket)
        {
            if(item == iKey)
            {
                return true;
            }
        }
        return false;
    }


};

class MyHashSet
{
    int keySpace; // buckets
    vector<Bucket*> hashTable;

  public:
    MyHashSet()
    {
        this->keySpace = 1000;
        for (int i=0; i<this->keySpace; i++)
        {
            this->hashTable.push_back(new Bucket());
        }
    }

    void add(int iKey)
    {
        this->hashTable[iKey % this->keySpace]->add(iKey);
    }

    void remove(int iKey)
    {
        this->hashTable[iKey % this->keySpace]->remove(iKey);
    }

    bool contains(int iKey)
    {
        return this->hashTable[iKey % this->keySpace]->contains(iKey);
    }
};

int main()
{
    cout<<"Hash Set :-";

    MyHashSet hashSet;
    
    cout<<boolalpha;

    hashSet.add(1);
    hashSet.add(2);
    cout<<"\nSet[1] = "<<hashSet.contains(1);
    cout<<"\nSet[3] = "<<hashSet.contains(3);

    hashSet.add(2);
    cout<<"\nSet[2] = "<<hashSet.contains(2);

    hashSet.remove(2);
    cout<<"\nSet[2] = "<<hashSet.contains(2);

    return 0;
}