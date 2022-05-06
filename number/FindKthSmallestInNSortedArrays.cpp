#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> ppi;

int findKthLargest(vector<vector<int>> arr, int K){
    priority_queue<ppi,vector<ppi>,greater<ppi>> minHeap;

    // add first element of each array
    for (int i = 0; i < arr.size(); i++){
        minHeap.push({arr[i][0], {i,0}});
    }

    int i=0, j=0, counter=0;
    while(!minHeap.empty() && counter<K) {
        auto curr=minHeap.top();minHeap.pop();
        i = curr.second.first;  // array number
        j = curr.second.second; // array index

        if(j+1 < arr[i].size()){
            minHeap.push({arr[i][j+1], {i, j+1}});
        }
        counter++;
    }

    return arr[i][j];
}

int main(){
    vector<vector<int>> arr{
        { 2, 7, 15 },
        { 3, 8, 11 },
        { 6, 9, 23 }
    };

    int nthLargest = findKthLargest(arr, 5);
    cout<<"5th Largest = "<<nthLargest<<endl;

    return 0;
}

