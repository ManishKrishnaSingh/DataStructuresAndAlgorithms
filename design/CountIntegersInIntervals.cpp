#include <bits/stdc++.h>

using namespace std;

/******************************************************************************
 * set::lower_bound(K):
 * returns an iterator to element which is equivalent to K or greater than K.
 * set::upper_bound(K):
 * returns an iterator to immediate next element which is just greater than K.
******************************************************************************/

class CountIntervals {
    int intCount;
    set<pair<int, int>> setIntervals;

  public:
    CountIntervals()
    {
        intCount = 0;
    }

    void add(int left, int right) // merge add intervals
    {
        //find iter to first element greater than left
        auto iter = setIntervals.upper_bound({left, INT_MIN});
        //check first element as well as previous interval overlap
        if(iter != setIntervals.begin() && (--iter)->second < left)
        {
            ++iter;
        }
        //check if it is last element in set and if fine to merge
        while(iter != setIntervals.end() && iter->first <= right)
        {
            //remove the prev effetive interger count
            intCount -= (iter->second - iter->first + 1);
            //adjust left,right after merge
            left  = min(left, iter->first);
            right = max(right, iter->second);
            //returns next element iterator
            iter = setIntervals.erase(iter);
        }
        //add the new integer count
        intCount += (right-left+1);
        // now, insert merged intervals
        setIntervals.insert({left, right});
    }

    int count()
    {
        return intCount;
    }
};

int main() {
    cout<<"Count Intervals\n";

    CountIntervals countIntervals;

    countIntervals.add(2, 5);
    countIntervals.add(7, 10);

    cout<<"Integer Count="<<countIntervals.count();

    return 0;
}
