#include <queue>
#include <climits>
#include <iostream>
#include <unordered_set>

using namespace std;

int dpSuperUgly(int primes[], int size, int N){
    int dp[N+1];
    for(int i=0; i<=N; i++){
        dp[i] = 1;
    }

    int pointer[size];
    for(int i=0; i<size; i++){
        pointer[i] = 1;
    }

    for (int i = 2; i <= N; i++){
        int index, minNumber = INT_MAX;
        for (int j = 0; j < size; j++){
            int num = dp[pointer[j]] * primes[j];
            if(num < minNumber){
                index = j;
                minNumber = num;
            }
        }
        pointer[index]++;
        dp[i] = minNumber;
    }
    return dp[N];
}

int pqSuperUgly(int primes[], int size, int N){
    if(N<0){
        return -1;
    }

    if(N==1){
        return 1;
    }

    unordered_set<int> unique;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<size; i++){
        minHeap.push(primes[i]);
    }

    int counter = 1;
    int top,uglyNumber;
    while(counter < N){
        top=minHeap.top();minHeap.pop();
        for(int i=0; i<size; i++){
            uglyNumber = top*primes[i];
            if(unique.find(uglyNumber)==unique.end()){
                minHeap.push(uglyNumber);
                unique.insert(uglyNumber);
            }
        }
        counter++;
    }

    return top;
}

int main(){
    int N = 7;
    int primes[] = {3, 7, 11, 13};
    int size = sizeof(primes)/sizeof(int);

    cout<< "Super Ugly Number = " << dpSuperUgly(primes, size, N) << endl;
    cout<< "Super Ugly Number = " << pqSuperUgly(primes, size, N) << endl;

    return 0;
}

