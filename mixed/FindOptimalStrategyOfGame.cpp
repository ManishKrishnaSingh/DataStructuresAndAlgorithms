#include <iostream>

using namespace std;

int optimalStrategyOfGame(int arr[], int n){
    int dp[n][n];

    int X, Y, Z;
    for (int i=0; i<n; i++) {
        for (int left=0,right=i; right<n; left++,right++) {
            X=Y=Z=0;

            if((left+2) <= right){
                X = dp[left+2][right];
            }
            if((left+1) <= (right-1)){
                Y = dp[left+1][right-1];
            }
            if(left <= (right-2)){
                Z = dp[left][right-2];
            }

            dp[left][right] = max(arr[left]+min(X,Y), arr[right] + min(Y,Z));
        }
    }

    return dp[0][n-1];
}

int main(){
    int arr[] = { 8, 15, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Value [Optimal Strategy] = " <<optimalStrategyOfGame(arr, n);

    return 0;
}

