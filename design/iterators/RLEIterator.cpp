#include <bits/stdc++.h>

using namespace std;

class RLEIterator
{
    int index; // curr
    vector<int> sequence;

  public:
    RLEIterator(vector<int> iSequence)
    {
        sequence = iSequence;
        index = 0;
    }

    int next(int n)
    {
        while (index < sequence.size())
        {
            if (sequence[index] >= n)
            {
                sequence[index] -= n;
                return sequence[index+1];
            }
            else
            {
                n -= sequence[index];
                index = index + 2;
            }
        }

        return -1;
    }
};


int main(){
    RLEIterator rIterator({3,8,0,9,2,5});

    cout<<"\nNext = "<<rIterator.next(2);
    cout<<"\nNext = "<<rIterator.next(1);
    cout<<"\nNext = "<<rIterator.next(1);
    cout<<"\nNext = "<<rIterator.next(2);

    return 0;
}