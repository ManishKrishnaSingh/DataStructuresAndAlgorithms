#include <bits/stdc++.h>

using namespace std;

class CustomStack
{
    int capacity;
    vector<int> stk;
    vector<int> inc;

  public:
    CustomStack(int maxSize)
    {
        capacity = maxSize;
    }

    void push(int x) {
        if (stk.size() < capacity)
        {
            stk.push_back(x);
            inc.push_back(0);
        }
    }

    int pop()
    {
        if(stk.empty())
        {
            return -1;
        }
        
        // pop back element
        int index = stk.size()-1;
        int result = stk[index];

        if (index > 0)
        {
            // add diff back to prev
            inc[index-1]+=inc[index];
        }

        // add into result
        result += inc[index];

        // pop back
        stk.pop_back();
        inc.pop_back();

        return result;
    }

    void increment(int K, int value)
    {
        int index=stk.size();
        index = min(K,index)-1;
        if (index >= 0)
        {
            inc[index] += value;
        }
    }
};

int main(){
    cout<<"Custom Stack";
    CustomStack stk(3);

    stk.push(1);
    stk.push(2);
    cout<<"\nPop = "<<stk.pop();

    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.increment(5, 100);
    stk.increment(2, 100);
    cout<<"\nPop = "<<stk.pop();
    cout<<"\nPop = "<<stk.pop();
    cout<<"\nPop = "<<stk.pop();
    cout<<"\nPop = "<<stk.pop();

    return 0;
}