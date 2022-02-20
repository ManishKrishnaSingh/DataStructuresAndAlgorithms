#include <bits/stdc++.h>

using namespace std;

void medianOfStream(int arr[], int n){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    int median = arr[0];
    maxHeap.push(arr[0]);
    cout<<"Median: "<<median;

    for (int i=1; i < n; i++){
        int key = arr[i];
        if (maxHeap.size()==minHeap.size()){
            if(key < median){
                maxHeap.push(key);
                median = maxHeap.top();
            } else {
                minHeap.push(key);
                median = minHeap.top();
            }
        } else if (maxHeap.size() > minHeap.size()){
            if(key < median){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(key);
            } else {
                minHeap.push(key);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
        } else if (maxHeap.size() < minHeap.size()){
            if (key > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(key);
            } else {
                maxHeap.push(key);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        cout<<" "<<median;
    }
    cout<<endl;
}

int main(){
    int arr1[] = {5, 15, 10, 20, 3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    medianOfStream(arr1, n1);

    int arr2[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    medianOfStream(arr2, n2);

    return 0;
}
