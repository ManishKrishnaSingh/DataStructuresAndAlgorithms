#include <queue>
#include <iostream>

using namespace std;

// pair<data, pair<row, index>> ppi
typedef pair<int, pair<int,int>> ppi;

vector<int> mergeKArrays(vector<vector<int>> arr){
    vector<int> result;

    priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;
    for(int k=0; k<arr.size(); k++){
        minHeap.push({arr[k][0], {k,0}});
    }

    while(!minHeap.empty()) {
        auto curr = minHeap.top();
        minHeap.pop();

        int row = curr.second.first;
        int idx = curr.second.second;

        result.push_back(curr.first);

        if(idx+1 < arr[row].size()){
            minHeap.push({arr[row][idx+1], {row, idx+1}});
        }
    }
    return result;
}

int main(){
    vector<vector<int>> arr={
        { 2,  6, 12},
        { 1,  9, 18},
        {23, 34, 98}
    };

    vector<int> output = mergeKArrays(arr);
    cout<<"Merged array:";
    for(auto data:output){
        cout<<" "<<data;
    }

    return 0;
}

