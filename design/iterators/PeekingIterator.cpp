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
    int next_val;
    bool iter_hasnext;
    public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {
        iter_hasnext=Iterator::hasNext();
        if (iter_hasnext)
        {
            next_val = Iterator::next();
        }
    }

    int peek()
    {
        return next_val;
    }

    int next()
    {
        int curr_next = next_val;
        iter_hasnext=Iterator::hasNext();
        if (iter_hasnext)
        {
            next_val = Iterator::next();
        }
        return curr_next;
    }

    bool hasNext() const
    {
        return iter_hasnext;
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