#include <iostream>

using namespace std;

int minStepsUtil(int height[], int left, int right, int h){
    if (left >= right){
        return 0;
    }

    int minHeightIdx = left;
    for (int i=left; i<right; i++){
        if (height[i] < height[minHeightIdx]){
            minHeightIdx = i;
        }
    }

    return min(
        right-left,
        minStepsUtil(height, left, minHeightIdx, height[minHeightIdx]) +
        minStepsUtil(height, minHeightIdx+1, right, height[minHeightIdx]) +
        height[minHeightIdx]-h);
}

int findMinimumSteps(int height[], int n){
    return minStepsUtil(height, 0, n, 0);
}

int main(){
    int height[] = { 2, 1, 2, 5, 1 };
    int n = sizeof(height) / sizeof(int);

    int minSteps=findMinimumSteps(height, n);
    cout<<"Minimum Steps = "<<minSteps<<endl;

    return 0;
}

