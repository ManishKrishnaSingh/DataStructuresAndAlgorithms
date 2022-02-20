#include <bits/stdc++.h>

using namespace std;

void printMedians(int A[], int N){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int median = 0;
    for (int i=0; i < N; i++){
        int num = A[i];
        if (maxHeap.size() > minHeap.size()){
            if (num < median){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top())/2;
        } else if (maxHeap.size() == minHeap.size()){
            if (num < median){
                maxHeap.push(num);
                median = maxHeap.top();
            } else {
                minHeap.push(num);
                median = minHeap.top();
            }
        } else if (maxHeap.size() < minHeap.size()){
            if (num > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top())/2;
        }
        cout << median << " ";
    }
}

int main(){
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int N = sizeof(A)/sizeof(A[0]);

    printMedians(A, N);
    return 0;
}

