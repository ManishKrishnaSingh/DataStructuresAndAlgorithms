#include <bits/stdc++.h>

using namespace std;

class kStacks {
  private:
    int *arr;
    int *next;
    int *top;
    int n, k;
    int free;

  public:
    kStacks(int k1, int n1){
        k = k1, n = n1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++){
            top[i] = -1;
        }

        //init free spaces
        free = 0;
        for(int i=0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    bool isFull() {
        return (free == -1);
    }

    void push(int item, int sn){
        if (isFull()){
            cout<<"\nStack Overflow\n"; return;
        }

        int idx = free;
        arr[idx] = item;

        free = next[idx];

        next[idx] = top[sn]; top[sn] = idx;
    }

    int pop(int sn){
        if (isEmpty(sn)){
            cout << "\nStack Underflow\n"; return INT_MAX;
        }

        int idx = top[sn];
        top[sn] = next[idx];

        next[idx]=free; free=idx;

        return arr[idx];
    }

    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }
};

int main(){
    int k=3, n=10;
    kStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout<<"Popped [Stack 2] is "<<ks.pop(2)<<endl;
    cout<<"Popped [Stack 1] is "<<ks.pop(1)<<endl;
    cout<<"Popped [Stack 0] is "<<ks.pop(0)<<endl;

    return 0;
}

