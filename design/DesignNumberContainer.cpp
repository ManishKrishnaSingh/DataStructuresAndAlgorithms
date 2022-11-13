#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
    // hash map of {index, number}
    unordered_map<int,int> mIndexToNum;
    // hash map of {number, set of {indexes}}
    unordered_map<int,set<int>> mNumToIndex;

  public:
    NumberContainers(){}

    void change(int idx, int num)
    {
        // check if index exists
        if(mIndexToNum.count(idx)){
            // current value with index
            int value = mIndexToNum[idx];
            // erase index from curr value
            mNumToIndex[value].erase(idx);
            // if still exists index for value
            if(mNumToIndex[value].size() > 0){
                // get new next index from the index set
                int newindex = *mNumToIndex[value].begin();
                mIndexToNum[newindex] = value; // assign
            }
        }
        // update num for index
        mIndexToNum[idx] = num;
        // add index with the number
        mNumToIndex[num].insert(idx);
    }

    int find(int num){
        int index = -1;
        if(mNumToIndex[num].size() > 0){
            index = *(mNumToIndex[num].begin());
        }
        return index;
    }
};

int main() {
    cout<<"Number Container System";

    NumberContainers numContainers;

    numContainers.change(10,25);
    numContainers.change(12,30);

    cout<<"\nIndex = "<<numContainers.find(28);
    cout<<"\nIndex = "<<numContainers.find(30);

    return 0;
}