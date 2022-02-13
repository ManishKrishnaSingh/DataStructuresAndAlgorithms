#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

void updateSegmentTreeUtil(int *sTree, int aBeg, int aEnd, int i, int diff, int idx){
    if (i < aBeg || i > aEnd){
        return;
    }

    sTree[idx] = sTree[idx] + diff;
    if (aEnd != aBeg){
        int mid = (aBeg+aEnd) >> 1;
        updateSegmentTreeUtil(sTree, aBeg, mid, i, diff, 2*idx + 1);
        updateSegmentTreeUtil(sTree, mid+1, aEnd, i, diff, 2*idx + 2);
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

int minRangeUtil(int* sTree, int aBeg, int aEnd, int qBeg, int qEnd, int idx){
    if(qBeg<=aBeg && qEnd>=aEnd){
        return sTree[idx];
    }

    if(aEnd < qBeg || aBeg > qEnd){
        return INT_MAX;
    }

    int mid = (aBeg+aEnd) >> 1;
    return min(minRangeUtil(sTree,aBeg,mid,qBeg,qEnd,2*idx+1), minRangeUtil(sTree,mid+1,aEnd,qBeg,qEnd,2*idx+2));
}

int minRange(int* sTree, int n, int qBeg, int qEnd){
    if(qBeg>qEnd || qBeg<0 || qEnd>=n){
        return -1;
    }
    return minRangeUtil(sTree, 0, n-1, qBeg, qEnd, 0);
}


int createSegmentTreeUtil(int arr[], int aBeg, int aEnd, int* sTree, int idx){
    if(aBeg == aEnd){
        sTree[idx] = arr[aBeg];
    } else {
        int mid = (aBeg+aEnd) >> 1;
        sTree[idx] = min(createSegmentTreeUtil(arr,aBeg,mid,sTree,2*idx+1), createSegmentTreeUtil(arr,mid+1,aEnd,sTree,2*idx+2));
    }
    return sTree[idx];
}

int* createSegmentTree(int arr[], int n){
    int x = ceil(log2(n));
    int size = 2*pow(2,x) - 1;

    int* sTree = new int[size];
    createSegmentTreeUtil(arr, 0, n-1, sTree, 0);

    return sTree;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *sTree = createSegmentTree(arr, n);
    cout<<"ST MIN [3-5] = "<<minRange(sTree,n,1,3)<<endl;

    updateSegmentTree(arr, sTree, n, 1, 10);
    cout<<"ST MIN [3-5] = "<<minRange(sTree,n,1,3)<<endl;

    return 0;
}

