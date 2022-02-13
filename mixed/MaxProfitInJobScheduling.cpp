#include <iostream>
#include <algorithm>

using namespace std;

typedef struct job{
    int start;
    int finish;
    int profit;
}Job;

bool compare(Job s1, Job s2){
    return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i){
    for (int j=i-1; j>=0; j--){
        if (arr[j].finish <= arr[i-1].start){
            return j;
        }
    }
    return -1;
}

int findMaxProfitUtil(Job arr[], int n){
    if (n == 1){
        return arr[0].profit;
    }

    // Profit when current job is included
    int inclProf = arr[n-1].profit;
    int i = latestNonConflict(arr, n);
    if (i != -1){
        inclProf += findMaxProfitUtil(arr, i+1);
    }

    // Profit when current job is excluded
    int exclProf = findMaxProfitUtil(arr, n-1);

    return max(inclProf, exclProf);
}

int findMaxProfit(Job arr[], int n){
    sort(arr, arr+n, compare);
    return findMaxProfitUtil(arr, n);
}

int main(){
    Job arr[] = {
        {3,  10,  20},
        {1,   2,  50},
        {6,  19, 100},
        {2, 100, 200}
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Optimal profit = " << findMaxProfit(arr, n);

    return 0;
}

