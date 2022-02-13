#include <cstring>
#include <iostream>

using namespace std;

bool hasTargetSum(int arr[], int n, int sumTarget){
    bool dp[sumTarget+1];
    memset(dp, false, sizeof(dp));

    dp[0]=true;
    for(int i=0; i<n; i++){
        if(arr[i]<=sumTarget){
            for(int j=sumTarget; j>=arr[i]; j--){
                if(dp[j-arr[i]] == true){
                    dp[j] = true;
                }
            }
        }
    }
    return dp[sumTarget];
}

int main(){
    int sumTarget = 11;

    int arr[] = { 6, 2, 5, 8, 1, 7, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bool result = hasTargetSum(arr, n, sumTarget);
    cout<<"Has Target Subset Sum = "<<boolalpha<<result<<endl;

    return 0;
}

