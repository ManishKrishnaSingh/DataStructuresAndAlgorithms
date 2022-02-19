#include <climits>
#include <iostream>

using namespace std;

bool isPossible(int boards[], int n, int minTime, int totalPainters){
    int currTime = 0;
    int requiredPainters = 1;
    for(int i=0; i<n; i++){
        currTime += boards[i];
        if(currTime > minTime){
            requiredPainters++;
            currTime = boards[i];
        }
    }
    if(requiredPainters<=totalPainters){
        return true;
    }
    return false;
}

int paintersPartition(int boards[], int n, int totalPainters){
    if(totalPainters>n){
        return -1;
    }

    int minTime=INT_MAX;

    int K=INT_MIN;
    int totalTime=0;
    for(int i=0; i<n; i++){
        K = max(K, boards[i]);
        totalTime += boards[i];
    }

    int low=K, high=totalTime;
    while(low <= high){
        int mid = (low+high) >> 1;
        if(isPossible(boards, n, mid, totalPainters)){
            high = mid-1;
            minTime = mid;
        } else {
            low = mid+1;
        }
    }
    return minTime;
}

int main(){
    int noOfPainters = 3;
    int arr[] = { 10, 20, 60, 50, 30, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int minTime = paintersPartition(arr, n, noOfPainters);
    cout<<"Minimum Time to Paint Board = "<<minTime<<endl;

    return 0;
}

