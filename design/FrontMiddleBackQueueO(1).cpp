#include <bits/stdc++.h>

using namespace std;

class FrontMiddleBackQueue {
    deque<int> xQueue;
    deque<int> yQueue;

    void x2yBalance(){
        if (xQueue.size() > yQueue.size()){
            yQueue.push_front(xQueue.back());
            xQueue.pop_back(); // pop back
        }
    }

    void y2xBalance(){
        if (yQueue.size() > (xQueue.size()+1)){
            xQueue.push_back(yQueue.front());
            yQueue.pop_front(); // pop front
        }
    }

  public:
    FrontMiddleBackQueue(){
        //TODO: Constructor
    }

    void pushFront(int value){
        xQueue.push_front(value);
        x2yBalance(); // balance
    }

    void pushMiddle(int value){
        xQueue.push_back(value);
        x2yBalance(); // balance
    }

    void pushBack(int value){
        yQueue.push_back(value);
        y2xBalance(); // balance
    }

    int popFront(){
        int res = -1;
        if (!xQueue.empty() || !yQueue.empty()){
            if (xQueue.empty()) {
                res=yQueue.front();
                yQueue.pop_front();
            } else {
                res=xQueue.front();
                xQueue.pop_front();
                y2xBalance(); //balance
            }
        }
        return res;
    }

    int popMiddle() {
        int res = -1;
        if (!xQueue.empty() || !yQueue.empty()){
            if (xQueue.size() == yQueue.size()) {
                res=xQueue.back(); 
                xQueue.pop_back();
            } else {
                res=yQueue.front();
                yQueue.pop_front();
            }
        }
        return res;
    }

    int popBack() {
        int res = -1;
        if (!xQueue.empty() || !yQueue.empty()){
            res=yQueue.back();
            yQueue.pop_back();
            x2yBalance(); //balance
        }
        return res;
    }
};

int main(){
    cout<<"Front Middle Back Queue\n";

    FrontMiddleBackQueue fmbQueue;

    fmbQueue.pushFront(11);
    fmbQueue.pushMiddle(10);
    fmbQueue.pushBack(45);
    fmbQueue.pushMiddle(21);

    cout<<fmbQueue.popFront()<<endl;
    cout<<fmbQueue.popMiddle()<<endl;
    cout<<fmbQueue.popBack()<<endl;

    return 0;
}