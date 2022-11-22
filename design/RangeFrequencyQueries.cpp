#include <bits/stdc++.h>

using namespace std;

class RangeFrequencyQuery
{
    unordered_map<int, vector<int>> mNumToIndex;

  public:
    RangeFrequencyQuery(vector<int>& arr)
    {
        for(int i=0; i<arr.size(); i++)
        {
            mNumToIndex[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        auto& v = mNumToIndex[value]; // get the vector of indexes for given value
        return (upper_bound(v.begin(),v.end(),right) - lower_bound(v.begin(),v.end(),left));
    }
};

int main() {
    cout<<"Range Frequency Query"<<endl;
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};

    RangeFrequencyQuery rangeFrequencyQuery(arr);
    cout<<"\nFrequency [1, 2, 4] = "<<rangeFrequencyQuery.query(1,  2,  4);
    cout<<"\nFrequency [0,11,33] = "<<rangeFrequencyQuery.query(0, 11, 33);

    return 0;
}