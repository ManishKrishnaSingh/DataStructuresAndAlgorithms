#include <iostream>

using namespace std;

int getBiTreeSum(int* biTree, int idx){
    int sum = 0;
    idx = idx + 1;
    while(idx > 0){
        sum += biTree[idx];
        // flip last set bit
        idx -= idx & (-idx);
    }
    return sum;
}

int getBiTreeRangeSum(int* biTree, int first, int last){
    return getBiTreeSum(biTree, last) - getBiTreeSum(biTree, first-1);
}

void updateBiTree(int* biTree, int idx, int n, int freq){
    idx = idx + 1;
    while(idx <= n){
        biTree[idx] += freq;
        // add last set bit
        idx += idx & (-idx);
    }
}

int* createBinaryIndexedTree(int frequency[], int n){
    int* biTree = new int[n+1];
    for(int i=0; i<=n; i++){
        biTree[i] = 0;
    }

    for(int i=0; i<n; i++){
        updateBiTree(biTree, i, n, frequency[i]);
    }
    return biTree;
}

int main(){
    int frequency[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(frequency) / sizeof(int);

    int* biTree = createBinaryIndexedTree(frequency, n);
    cout<<"BIT SUM [0,5] = "<<getBiTreeSum(biTree, 5)<<endl;

    frequency[3] += 10;

    updateBiTree(biTree, 3, n, 10);
    cout<<"BIT SUM [0,5] = "<<getBiTreeSum(biTree, 5)<<endl;

    cout<<"BIT SUM [0,4] = "<<getBiTreeSum(biTree, 4)<<endl;
    cout<<"BIT SUM [0,8] = "<<getBiTreeSum(biTree, 8)<<endl;
    cout<<"BIT SUM [5,8]*= "<<getBiTreeRangeSum(biTree, 5, 8)<<endl;

    return 0;
}

