#include <bits/stdc++.h>

using namespace std;

void updateSegmentTreeUtil(int *sTree, int low, int high, int i, int diff, int idx){
    if (i < low || i > high){
        return;
    }

    sTree[idx] = sTree[idx] + diff;
    if (low != high){
        int mid = (low+high) >> 1;
        updateSegmentTreeUtil(sTree, low, mid, i, diff, 2*idx + 1);
        updateSegmentTreeUtil(sTree, mid+1, high, i, diff, 2*idx + 2);
    }
}

void updateSegmentTree(int arr[], int *sTree, int n, int idx, int newValue){
    if (idx < 0 || idx > n-1){
        return;
    }

    int curr = arr[idx];
    arr[idx] = newValue;
    int diff = newValue - curr;
    updateSegmentTreeUtil(sTree, 0, n-1, idx, diff, 0);
}

int minRangeUtil(int* sTree, int low, int high, int qBeg, int qEnd, int idx){
    if(qBeg<=low && qEnd>=high){
        return sTree[idx];
    }

    if(high < qBeg || low > qEnd){
        return INT_MAX;
    }

    int mid = (low+high) >> 1;
    return min(
        minRangeUtil(sTree, low, mid, qBeg, qEnd, 2*idx+1),
        minRangeUtil(sTree, mid+1, high, qBeg, qEnd, 2*idx+2)
    );
}

int minRange(int* sTree, int n, int qBeg, int qEnd){
    if(qBeg>qEnd || qBeg<0 || qEnd>=n){
        return -1;
    }
    return minRangeUtil(sTree, 0, n-1, qBeg, qEnd, 0);
}


int buildSegmentTreeUtil(int arr[], int low, int high, int* sTree, int idx){
    if(low == high){
        sTree[idx] = arr[low];
    } else {
        int mid = (low+high) >> 1;
        sTree[idx] = min(
            buildSegmentTreeUtil(arr, low, mid, sTree, 2*idx+1),
            buildSegmentTreeUtil(arr, mid+1, high, sTree, 2*idx+2)
        );
    }
    return sTree[idx];
}

int* buildSegmentTree(int arr[], int n){
    int x = ceil(log2(n));
    int size = 2*pow(2,x) - 1;

    int* sTree = new int[size];
    buildSegmentTreeUtil(arr, 0, n-1, sTree, 0);

    return sTree;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *sTree = buildSegmentTree(arr, n);
    cout<<"ST MIN [3-5] = "<<minRange(sTree,n,1,3)<<endl;

    updateSegmentTree(arr, sTree, n, 1, 10);
    cout<<"ST MIN [3-5] = "<<minRange(sTree,n,1,3)<<endl;

    return 0;
}