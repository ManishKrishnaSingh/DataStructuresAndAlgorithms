#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
    set<int> infiniteSet;

  public:
    SmallestInfiniteSet(){
        infiniteSet.clear();
        for(int i=1;i<=1000;i++){
            infiniteSet.insert(i);
        }
    }

    int popSmallest(){
        int smallest = *infiniteSet.begin();
        infiniteSet.erase(infiniteSet.begin());
        return smallest;
    }

    void addBack(int num){
        infiniteSet.insert(num);
    }
};

class SmallestInfiniteSetPQ {
    unordered_set<int> unique;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    public:
    SmallestInfiniteSetPQ(){
        for(int i=1;i<=1000;i++){
            minHeap.push(i);
            unique.insert(i);
        }
    }
    
    int popSmallest(){
        int top = minHeap.top();
        minHeap.pop();
        unique.erase(top);
        return top;
    }
    
    void addBack(int num){
        if(unique.count(num)){
            return;
        }
        minHeap.push(num);
        unique.insert(num);
    }
};

int main(){
    cout<<"Smallest in Infinite Set\n";

    SmallestInfiniteSet sInfiniteSet;

    sInfiniteSet.addBack(2);
    sInfiniteSet.popSmallest();
    sInfiniteSet.popSmallest();
    sInfiniteSet.popSmallest();
    sInfiniteSet.addBack(1);
    sInfiniteSet.popSmallest();
    sInfiniteSet.popSmallest();
    sInfiniteSet.popSmallest();

    return 0;
}