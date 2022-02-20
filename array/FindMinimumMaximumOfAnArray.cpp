#include <iostream>

using namespace std;

typedef struct minmax{
    int min;
    int max;
}MinMax;

MinMax findMinMax(int input[], int low, int high){
    MinMax result;

    if(low==high){
        result.min = input[low];
        result.max = input[low];
    } else if(low+1==high){
        result.min = min(input[low], input[high]);
        result.max = max(input[low], input[high]);
    } else {
        int mid = (low+high) >> 1;
        MinMax left = findMinMax(input, low, mid);
        MinMax right = findMinMax(input, mid+1, high);
        result.min = min(left.min, right.min);
        result.max = max(left.max, right.max);
    }
    return result;
}

int main(){
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int n = sizeof(arr) / sizeof(int);

    MinMax result = findMinMax(arr, 0, n-1);
    cout << "Minimum Element = "<<result.min<<endl;
    cout << "Maximum Element = "<<result.max<<endl;

    return 0;
}

