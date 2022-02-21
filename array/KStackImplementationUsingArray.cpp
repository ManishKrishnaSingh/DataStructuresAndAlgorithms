#include <bits/stdc++.h>

using namespace std;

class kStacks {
  private:
    int K, N;

    int *arr;
    int *next;

    int *top;

    int free;

  public:
    kStacks(int nOfStack, int capacity){
        K = nOfStack;
        N = capacity;

        // init top array
        top = new int[K];
        for(int i=0; i<K; i++){
            top[i] = -1;
        }

        // init next array
        arr  = new int[N];
        next = new int[N];
        for(int i=0; i<N-1; i++){
            next[i] = i+1;
        }
        next[N-1] = -1;

        free = 0; // free index
    }

    void push(int stkIdentifier, int key){
        if (isFull()){
            cout<<"\nStack Overflow\n";
            return;
        }

        int index = free;
        arr[index] = key;
        free = next[index];

        next[index] = top[stkIdentifier];
        top[stkIdentifier] = index;
    }

    int pop(int stkIdentifier){
        if (isEmpty(stkIdentifier)){
            cout<<"\nStack Underflow\n";
            return INT_MAX;
        }

        int index = top[stkIdentifier];
        top[stkIdentifier] = next[index];

        next[index]=free;
        free=index;

        return arr[index];
    }

    bool isFull() {
        return (free == -1);
    }

    bool isEmpty(int stkIdentifier) {
        return (top[stkIdentifier] == -1);
    }
};

int main(){
    int K=3, N=12;
    kStacks stk(K,N);

    stk.push(0, 41);
    stk.push(0, 95);
    stk.push(0, 77);
    stk.push(0, 64);

    stk.push(1, 17);
    stk.push(1, 50);
    stk.push(1, 34);
    stk.push(1, 35);

    stk.push(2, 15);
    stk.push(2, 55);
    stk.push(2, 45);
    stk.push(2, 23);

    cout<<"POP[0]="<<stk.pop(0)<<endl;
    cout<<"POP[1]="<<stk.pop(1)<<endl;
    cout<<"POP[2]="<<stk.pop(2)<<endl;

    return 0;
}

