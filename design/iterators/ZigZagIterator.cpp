#include <bits/stdc++.h>

using namespace std;

class ZigzagIterator
{
    queue<pair<vector<int>::iterator,vector<int>::iterator>> queueIterator;

  public:
    ZigzagIterator(vector<int>& x, vector<int>& y)
    {
        if (x.size())
        {
            queueIterator.push({x.begin(), x.end()});
        }
        if (y.size())
        {
            queueIterator.push({y.begin(), y.end()});
        }
    }

    int next()
    {
        vector<int>::iterator iterBeg = queueIterator.front().first;
        vector<int>::iterator iterEnd = queueIterator.front().second;

        queueIterator.pop(); // pop front from the iterator queue

        if (iterBeg+1 != iterEnd)
        {
            queueIterator.push({iterBeg+1, iterEnd});
        }

        return *(iterBeg);
    }

    bool hasNext()
    {
        return !queueIterator.empty();
    }
};

int main(){
    vector<int> x = {1, 6, 8, 9};
    vector<int> y = {2, 4, 7, 5, 7, 5};

    ZigzagIterator zIterator(x, y);

    cout<<"VISIT [ZigZag] :";
    while (zIterator.hasNext())
    {
        cout<<" "<<zIterator.next();
    }

    return 0;
}