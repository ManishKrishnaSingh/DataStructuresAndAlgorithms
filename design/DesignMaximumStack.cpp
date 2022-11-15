#include <bits/stdc++.h>

using namespace std;

class MaxStack {
    int counter;
    set<pair<int, int>> sStack;
    set<pair<int, int>> sValue;

  public:
    MaxStack()
    {
        counter = -1;
    }

    void push(int num)
    {
        counter++;
        sStack.insert({counter, num});
        sValue.insert({num, counter});
    }

    int pop()
    {
        auto top = *sStack.rbegin();
        sStack.erase(top);
        sValue.erase({top.second, top.first});
        return top.second;
    }

    int top()
    {
        return sStack.rbegin()->second;
    }

    int peekMax()
    {
        return sValue.rbegin()->first;
    }

    int popMax()
    {
        auto max = *sValue.rbegin();
        sValue.erase(max);
        sStack.erase({max.second, max.first});
        return max.first;
    }
};

int main(){
    cout<<"Max Stack";
    MaxStack maxStack;

    maxStack.push(5);
    maxStack.push(1);
    maxStack.push(5);

    cout<<"\nTop = "<<maxStack.top();
    cout<<"\nMax = "<<maxStack.popMax();
    cout<<"\nTop = "<<maxStack.top();
    cout<<"\nMax = "<<maxStack.peekMax();
    cout<<"\nMax = "<<maxStack.pop();
    cout<<"\nTop = "<<maxStack.top();

    return 0;
}