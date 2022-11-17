#include <bits/stdc++.h>

using namespace std;

class NestedInteger
{
  public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    stack<vector<NestedInteger>::iterator> stkBeg, stkEnd;

  public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        stkBeg.push(nestedList.begin());
        stkEnd.push(nestedList.end());
    }

    int next(){
        hasNext();
        return (stkBeg.top()++)->getInteger();
    }

    bool hasNext()
    {
        while (stkBeg.size())
        {
            if (stkBeg.top() == stkEnd.top())
            {
                stkBeg.pop();
                stkEnd.pop();
            }
            else
            {
                auto top = stkBeg.top();
                if (top->isInteger())
                {
                    return true;
                }
                stkBeg.top()++;
                stkBeg.push(top->getList().begin());
                stkEnd.push(top->getList().end());
            }
        }

        return false;
    }
};

int main(){
    cout<<"Nested Iterator\n";
    return 0;
}