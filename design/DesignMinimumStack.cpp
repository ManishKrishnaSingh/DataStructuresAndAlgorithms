#include <bits/stdc++.h>

using namespace std;

class MinStack {
    stack<pair<int,int>> stk;

  public:
    MinStack() { }

    void push(int num) {
        if (stk.empty())
        {
            stk.push({num, num});
        }
        else
        {
            stk.push({num, min(num,stk.top().second)});   
        }
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};

int main(){
    cout<<"Min Stack";
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<"\nMin = "<<minStack.getMin();

    minStack.pop();
    cout<<"\nTop = "<<minStack.top();
    cout<<"\nMin = "<<minStack.getMin();

    return 0;
}