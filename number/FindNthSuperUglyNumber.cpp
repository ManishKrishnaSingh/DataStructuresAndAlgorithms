#include <bits/stdc++.h>

using namespace std;

int dpSuperUgly(int primes[], int size, int n)
{
    int dp[n+1];

    int index[size] = {0}; // stores prime indexes
    int multi[size] = {0}; // store the multipliers

    dp[0] = 1;
    for(int i=0; i<n; i++)
    {
        int  minimum = INT_MAX;
        for(int j=0; j<size; j++)
        {
            multi[j] = dp[index[j]]*primes[j];
            minimum = min(minimum, multi[j]);
        }

        for(int j=0; j<size; j++)
        {
            if(minimum==multi[j])
            {
                index[j]++;
                dp[i+1] = multi[j];
            }
        }
    }

    return dp[n-1];
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

