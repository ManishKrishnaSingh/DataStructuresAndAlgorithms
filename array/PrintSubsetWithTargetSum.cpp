#include <bits/stdc++.h>

using namespace std;

bool **dp;

void display(const vector<int>& subset){
    cout<<"Subset:";
    for(int i=0; i<subset.size(); i++){
        cout<<" "<<subset[i];
    }
    cout<<endl;
}

void PrintSubsets(int arr[], int i, int sum, vector<int>& subset){
    if (i == 0 && sum != 0 && dp[0][sum]){
        subset.push_back(arr[i]);
        if (arr[i] == sum){
            display(subset);
        }
        return;
    }

    if (i == 0 && sum == 0){
        display(subset); return;
    }

    // if current element excluded
    if (dp[i-1][sum]){
        vector<int> newsubset = subset;
        PrintSubsets(arr, i-1, sum, newsubset);
    }

    // if current element included
    if (sum >= arr[i] && dp[i-1][sum-arr[i]]){
        subset.push_back(arr[i]);
        PrintSubsets(arr, i-1, sum-arr[i], subset);
    }
}

void findSubsetsWithTargetSum(int arr[], int n, int sumTarget){
    if (n == 0 || sumTarget < 0){
        return;
    }

    dp = new bool*[n];
    for(int i=0; i<n; i++){
        dp[i] = new bool[sumTarget+1];
        dp[i][0] = true;
    }

    if (arr[0] <= sumTarget){
        dp[0][arr[0]] = true;
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<=sumTarget; j++){
            if(arr[i] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if (!dp[n-1][sumTarget]){
        cout<<"No subsets!"<<endl; return;
    }

    vector<int> subset;
    PrintSubsets(arr, n-1, sumTarget, subset);
}

int main(){
    int sumTarget = 10;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubsetsWithTargetSum(arr, n, sumTarget);
    return 0;
}

