#include <bits/stdc++.h>

using namespace std;

class Iterator
{
    struct Data;
    Data* data;

  public:
    Iterator(const vector<int>& nums);

    Iterator(const Iterator& iter);

    int next();

    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
    int nextValue;
    bool pHasNext;

  public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {
        pHasNext = Iterator::hasNext();
        if (pHasNext)
        {
            nextValue = Iterator::next();
        }
    }

    int peek()
    {
        return nextValue;
    }

    int next()
    {
        int currNext = nextValue;
        pHasNext = Iterator::hasNext();
        if (pHasNext)
        {
            nextValue = Iterator::next();
        }
        return currNext;
    }

    bool hasNext() const
    {
        return pHasNext;
    }
};

int main(){
    PeekingIterator pIterator({1, 2, 3});

    cout<<"\nNext = "<<pIterator.next();    // 1
    cout<<"\nPeek = "<<pIterator.peek();    // 2
    cout<<"\nNext = "<<pIterator.next();    // 2
    cout<<"\nNext = "<<pIterator.next();    // 3

    cout<<"\nHas Next = "<<pIterator.hasNext();

    return 0;
}