#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> KeyValuePair;

class Bucket
{
    vector<KeyValuePair*> bucket;

  public :
    Bucket()
    {
        //TODO:
    }

    void put(int iKey, int iValue)
    {
        bool keyExistInBucket = false;
        for(auto pKeyValue : this->bucket)
        {
            if(pKeyValue->first == iKey)
            {
                keyExistInBucket = true;
                pKeyValue->second = iValue;
            }
        }
        if (keyExistInBucket == false)
        {
            this->bucket.push_back(new KeyValuePair({iKey, iValue}));
        }
    }

    int get(int iKey)
    {
        for(auto pKeyValue : this->bucket)
        {
            if(pKeyValue->first == iKey)
            {
                return pKeyValue->second;
            }
        }
        return -1;
    }

    void remove(int iKey)
    {
        for(auto pKeyValue : this->bucket)
        {
            if(pKeyValue->first == iKey)
            {
                this->bucket.erase(find(bucket.begin(),bucket.end(),pKeyValue)); break;
            }
        }
    }
};

class MyHashMap
{
    int keySpace; // buckets
    vector<Bucket*> hashTable;

  public:
    MyHashMap()
    {
        this->keySpace = 1000;
        for (int i=0; i<this->keySpace; i++)
        {
            this->hashTable.push_back(new Bucket());
        }
    }

    void put(int iKey, int iValue)
    {
        this->hashTable[iKey % this->keySpace]->put(iKey, iValue);
    }

    int get(int iKey)
    {
        return this->hashTable[iKey % this->keySpace]->get(iKey);
    }

    void remove(int iKey)
    {
        this->hashTable[iKey % this->keySpace]->remove(iKey);
    }
};

int main()
{
    cout<<"Hash Map :-";

    MyHashMap mKayValue;

    mKayValue.put(1, 1);
    mKayValue.put(2, 2);
    cout<<"\nmap[1] = "<<mKayValue.get(1);
    cout<<"\nmap[3] = "<<mKayValue.get(3);

    mKayValue.put(2, 1);
    cout<<"\nmap[2] = "<<mKayValue.get(2);

    mKayValue.remove(2);
    cout<<"\nmap[2] = "<<mKayValue.get(2);

    return 0;
}