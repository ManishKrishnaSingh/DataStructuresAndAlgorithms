#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue{
    vector<int> queue;
    int head, size, capacity;

  public:
    MyCircularQueue(int K){
        capacity = K;
        queue.resize(K);
        head = size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    bool enQueue(int value){
        if (isFull()){
            return false;
        }
        queue[(head+size)%capacity] = value;
        size++; // increase queue size by 1
        return true;
    }

    bool deQueue(){
        if (isEmpty()){
            return false;
        }
        // update the head index
        head = (head+1)%capacity;
        size--; // decrease queue size by 1
        return true;
    }

    int Front(){
        if (isEmpty()){
            return -1;
        }
        return queue[head];
    }

    int Rear(){
        if (isEmpty()){
            return -1;
        }
        return queue[(head+size-1)%capacity];
    }
};

int main()
{
    cout<<"My Circular Queue:-";

    MyCircularQueue myQueue(3);

    cout<<"\n=> "<<myQueue.enQueue(1); // true
    cout<<"\n=> "<<myQueue.enQueue(2); // true
    cout<<"\n=> "<<myQueue.enQueue(3); // true
    cout<<"\n=> "<<myQueue.enQueue(4); // false
    cout<<"\n=> "<<myQueue.Rear();     // 3
    cout<<"\n=> "<<myQueue.isFull();   // true
    cout<<"\n=> "<<myQueue.deQueue();  // true
    cout<<"\n=> "<<myQueue.enQueue(4); // true
    cout<<"\n=> "<<myQueue.Rear();     // 4

    return 0;
}