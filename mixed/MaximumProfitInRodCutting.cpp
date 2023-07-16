#include <vector>
#include <iostream>

using namespace std;

int findMaxProfitFromRodCut(int arr[], int n){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i]=0;
        for(int j=0; j<i; j++){
            dp[i] = max(dp[i], arr[j]+dp[i-j-1]);
        }
    }
    return dp[n];
}

int main(){
    int arr[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(arr) / sizeof(int);

    int profit = findMaxProfitFromRodCut(arr, n);
    cout<<"Maximum Profit [CR] = "<<profit<<endl;

    return 0;
}

